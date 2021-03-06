//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        FileLevelLoader.h                         //
//            █ █        █ █        CoreLightsOff                             //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __CoreLightsOff_include_FileLevelLoader_h__
#define __CoreLightsOff_include_FileLevelLoader_h__

//std
#include <string>
//CoreLightsOff
#include "CoreLightsOff_Utils.h"
#include "ILevelLoader.h"
#include "Light.h"


NS_CORELIGHTSOFF_BEGIN

class FileLevelLoader : public ILevelLoader
{
    // Constants //
public:
    ///@brief The char that represents the Light On.
    ///@note To this class loads the board correctly the file MUST
    ///      represents the on light with this char.
    static const char kLightOnChar;

    ///@brief The char that represents the Light Off.
    ///@note To this class loads the board correctly the file MUST
    ///      represents the on light with this char.
    static const char kLightOffChar;


    // CTOR/DTOR //
public:
    ///@brief Loads the Board from file located in filename.
    ///@throws
    ///     std::system_error exception if it cannot open a
    ///     file with the given filename.
    FileLevelLoader(const std::string &filename);

    ///@brief Virtual destructor.
    virtual ~FileLevelLoader();


    // Overriden Methods //
public:
    ///@brief Gets the board loaded.
    ///@returns The reference for the board.
    const Light::Board& getBoard() const override;

    ///@brief Gets how many lighs are on.
    ///@returns The lights on count.
    ///@see FileLevelLoader::getLightsOff
    int getLightsOnCount() const override;

    ///@brief Gets how many lighs are off.
    ///@returns The lights off count.
    ///@see FileLevelLoader::getLightsOn
    int getLightsOffCount() const override;


    // iVars //
private:
    Light::Board m_board;
    int          m_lightsOnCount;
    int          m_lightsOffCount;

};


NS_CORELIGHTSOFF_END
#endif // defined(__CoreLightsOff_include_FileLevelLoader_h__) //
