#ifndef INSTRUCTION_SET
#define INSTRUCTION_SET

/**
 ************************************
 *    COMMUNICATION INSTRUCTIONS    *
 ************************************
 *  PING: Asks for confirmation from receiving device.
 *      If received device should respond with RECEIVED.
 *
 *  ACK: Sent as a confirmation of receiving an instruction or data.
 *
 *  COMPLETED: Sent when sender has completed execution of previous instruction.
 *      This is not sent when PING is executed as RECIVED is enough.
 *
 *  NAK: Sent when receiving an invalid instruction or an instruction that could not or will not be executed.
 *
 ************************************
 *    DATA TRANSFER INSTRUCTIONS    *
 ************************************
 *  REQUESTSEND: Sent when sender wishes to send more than 64 bytes of data.
 *      The next TWO bytes of data must be the number of bytes that are to be sent.
 *
 *  READYRECEIVE: Sent when the sending device is ready to recieve the data from REQUESTSEND.
 *
 *****************************
 *    SETTER INSTRUCTIONS    *
 *****************************
 *  SETSCENE: Indicates that the sender would like to send a scene to be set to a particular index.
 *      The next byte must be the scene id. After this the sender must REQUESTSEND, then once receiving
 *      READYRECEIVE it will then send the scene. It should next get a COMPLETED message after the scene is set.
 *
 *  SETSCENEDELAY: Tells the Arduino to set the delay between scenes. The next two bytes must be the unsigned int of milliseconds to delay
 *      between switching scenes. This value affects the demo modes as well as the play mode.
 *
 *  SETCOLOR: Sets one of the colors. The next byte must be the color id, and the THREE bytes
 *      after the first must be the color EX: [1 Byte ID][3 Byte COLOR]. White is always color id 0 and black is
 *      always color id 15, these two ids can not be changed and any attempt to will return NAK.
 *
 *  SETBRIGHTNESS: Sets the brightness of the screen, valid values range from 0 to 255. The next byte sent must be the brightness.
 *
 *  SETCORRECTION: Sets the color correction of the screen. The next THREE bytes sent should be the color correction.
 *
 *  SETTEMPERATURE: Sets the color temperature of the screen. The next THREE bytes sent should be the color temperature.
 *
 *****************************
 *    GETTER INSTRUCTIONS    *
 *****************************
 *  GETMAXLEDS: Asks the Arduino to reply with the number of leds it is controlling.
 *
 *  GETMAXNUMCOLORS: Asks the Arduino to reply with the maximum number of colors we can predefine.
 *
 *  GETMAXSCENES: Asks the Arduino to reply with maximum number of scenes it can store.
 *
 *  GETSCENE: Asks the Arduino to send a scene from a particular index. the next byte must be the scene id the sender
 *      wants. After this the sender must wait for a REQUESTSEND instruction and reply with a READYRECEIVE when it ready
 *      to receive the scene data. After receiving all the data it expects to the sender must reply with a COMPLETED.
 *
 *  GETSCENEDELAY: Asks the Arduino for the delay between scenes. The next two bytes must be the unsigned int of milliseconds to delay
 *      between switching scenes. This value affects the demo modes as well as the play mode.
 *
 *  GETCOLOR: Asks the Arduino for the color by id. The next byte sent must be the id of the color wanted.
 *
 *  GETBRIGHTNESS: Asks the Arduino for the current brightness the screen is set to.
 *
 *  GETCORRECTION: Asks the Arduino for the color correction. The color correction is THREE bytes of data.
 *
 *  GETTEMPERATURE: Asks the Arduino for the color temperature. The color temperature is THREE bytes of data.
 *
 ******************************
 *    CONTROL INSTRUCTIONS    *
 ******************************
 *  DEMOMODE: TElls the Arduino to run a built in demo. the next byte must be the id of the demo.
 *
 *  CLEARSCREEN: Tells the Arduino to clear the sceen to black.
 *
 *  SHOWSCENE: Tells the Arduino to display a particular scene and then to pause. The next byte must be the scene id to display.
 *
 *  PLAY: Tells the Arduino to display the scenes in increasing numerical order starting from a default of scene 0.
 *
 *  PAUSE: Tells the Arduino to stop displaying the scenes but to continue from when it stoped when PLAY is received. 
 *
 *  STOP: Tells the Arduino to stop displaying the scenes and to start from scene 0 again when play is received.
 *
 *  RESET: Tells the Arduino to clear all stored data and return to power on state
 *
 */

//     | INSTRUCTION_[CommandName] | DEC |     BIN     | ASCII Character |
#define  INSTRUCTION_PING             32  //00100000          ' '
#define  INSTRUCTION_ACK              33  //00100001          '!'
#define  INSTRUCTION_COMPLETED        34  //00100010          '"'
#define  INSTRUCTION_NAK              35  //00100011          '#'

#define  INSTRUCTION_REQUESTSEND      44  //00101100          ','
#define  INSTRUCTION_READYRECEIVE     45  //00101101          '-'

#define  INSTRUCTION_SETSCENE         65  //01000001          'A'
#define  INSTRUCTION_SETSCENEDELAY    66  //01000010          'B'
#define  INSTRUCTION_SETCOLOR         67  //01000011          'C'
#define  INSTRUCTION_SETBRIGHTNESS    68  //01000100          'D'
#define  INSTRUCTION_SETCORRECTION    69  //01000101          'E'
#define  INSTRUCTION_SETTEMPERATURE   70  //01000110          'F'

#define  INSTRUCTION_GETMAXLEDS       94  //01011110          '^'
#define  INSTRUCTION_GETMAXNUMCOLORS  95  //01011111          '_'
#define  INSTRUCTION_GETMAXSCENES     96  //01100000          '`'
#define  INSTRUCTION_GETSCENE         97  //01100001          'a'
#define  INSTRUCTION_GETSCENEDELAY    98  //01100010          'b'
#define  INSTRUCTION_GETCOLOR         99  //01100011          'c'
#define  INSTRUCTION_GETBRIGHTNESS   100  //01100100          'd'
#define  INSTRUCTION_GETCORRECTION   101  //01100101          'e'
#define  INSTRUCTION_GETTEMPERATURE  102  //01100110          'f'

#define  INSTRUCTION_DEMOMODE        120  //01111000          'x'
#define  INSTRUCTION_CLEARSCREEN     121  //01111001          'y'
#define  INSTRUCTION_SHOWSCENE       122  //01111010          'z'
#define  INSTRUCTION_PLAY            123  //01111011          '{'
#define  INSTRUCTION_PAUSE           124  //01111100          '|'
#define  INSTRUCTION_STOP            125  //01111101          '}'
#define  INSTRUCTION_RESET           126  //01111110          '~'

#endif //INSTRUCTION_SET