
#include "Ponger.hh"

#include "umlrtcommsportrole.hh"
#include "umlrtmessage.hh"
#include "umlrtslot.hh"
#include <cstddef>
#include "umlrtcapsuleclass.hh"
#include "umlrtframeservice.hh"
class UMLRTRtsInterface;
struct UMLRTCommsPort;

Capsule_Ponger::Capsule_Ponger( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * * internal, bool isStat )
: UMLRTCapsule( NULL, cd, st, border, internal, isStat )
, pongPort( borderPorts[borderport_pongPort] )
, hitCount( 0 )
, currentState( SPECIAL_INTERNAL_STATE_UNVISITED )
{
    stateNames[State1] = "State1";
    stateNames[SPECIAL_INTERNAL_STATE_TOP] = "<top>";
    stateNames[SPECIAL_INTERNAL_STATE_UNVISITED] = "<uninitialized>";
}







void Capsule_Ponger::bindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_pongPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_pongPort, index, true );
            break;
        }
}

void Capsule_Ponger::unbindPort( bool isBorder, int portId, int index )
{
    if( isBorder )
        switch( portId )
        {
        case borderport_pongPort:
            UMLRTFrameService::sendBoundUnbound( borderPorts, borderport_pongPort, index, false );
            UMLRTFrameService::disconnectPort( borderPorts[borderport_pongPort], index );
            break;
        }
}


void Capsule_Ponger::inject( const UMLRTMessage & message )
{
    msg = &message;
    switch( currentState )
    {
    case State1:
        currentState = state_____State1( &message );
        break;
    default:
        break;
    }
}

void Capsule_Ponger::initialize( const UMLRTMessage & message )
{
    msg = &message;
    actionchain_____Initial( &message );
    currentState = State1;
}

const char * Capsule_Ponger::getCurrentStateString() const
{
    return stateNames[currentState];
}




void Capsule_Ponger::update_state( Capsule_Ponger::State newState )
{
    currentState = newState;
}

void Capsule_Ponger::transitionaction_____Initial( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/PingPongV2/PingPongV2.uml PingPongV2::Ponger transition subvertex0,State1,ping:pongPort */
    log.log("Ponger is ready");
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Ponger::transitionaction_____transition1( const UMLRTMessage * msg )
{
    #define rtdata ( (void *)msg->getParam( 0 ) )
    /* UMLRTGEN-USERREGION-BEGIN platform:/resource/PingPongV2/PingPongV2.uml PingPongV2::Ponger transition State1,State1 */
    // Reply to a ping message by sending a pong.
    log.log("Ping received!");
    if (hitCount <=5){
    if ( pongPort.pong().send() ){
    log.log( "pong sent!");
    } else {
    log.log( "Error sending Pong!");
    }
    } else { log.log( "Missed! Game over!");}
    hitCount++;
    /* UMLRTGEN-USERREGION-END */
    #undef rtdata
}

void Capsule_Ponger::actionchain_____Initial( const UMLRTMessage * msg )
{
    transitionaction_____Initial( msg );
    update_state( State1 );
}

void Capsule_Ponger::actionchain_____transition1( const UMLRTMessage * msg )
{
    update_state( SPECIAL_INTERNAL_STATE_TOP );
    transitionaction_____transition1( msg );
    update_state( State1 );
}

Capsule_Ponger::State Capsule_Ponger::state_____State1( const UMLRTMessage * msg )
{
    switch( msg->destPort->role()->id )
    {
    default:
        this->unexpectedMessage();
        break;
    }
    return currentState;
}


static const UMLRTCommsPortRole portroles_border[] = 
{
    {
        Capsule_Ponger::port_pongPort,
        "PingPongProtocol",
        "pongPort",
        "",
        1,
        true,
        false,
        false,
        false,
        false,
        false,
        true
    }
};

static const UMLRTCommsPortRole portroles_internal[] = 
{
    {
        Capsule_Ponger::port_log,
        "Log",
        "log",
        "",
        0,
        false,
        false,
        false,
        false,
        true,
        false,
        false
    }
};

static void instantiate_Ponger( const UMLRTRtsInterface * rts, UMLRTSlot * slot, const UMLRTCommsPort * * borderPorts )
{
    const UMLRTCommsPort * * internalPorts = UMLRTFrameService::createInternalPorts( slot, &Ponger );
    slot->capsule = new Capsule_Ponger( &Ponger, slot, borderPorts, internalPorts, false );
}

const UMLRTCapsuleClass Ponger = 
{
    "Ponger",
    NULL,
    instantiate_Ponger,
    0,
    NULL,
    1,
    portroles_border,
    1,
    portroles_internal
};

