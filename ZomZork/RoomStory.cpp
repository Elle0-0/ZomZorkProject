#include "RoomStory.h"

namespace storyline {

    namespace bedroom {
        std::string getText() {
            return "You wake up un-aware of what has happened, you wife lays on the \nfloor seemly unconcious, you need to leave the house.";
        }
    }

    namespace kitchen {
        std::string getText() {
            return "there is a knife on the table and you hear weird noises outside,\nmaybe you should take it?";
        }
    }

    namespace bathroom {
        std::string getText() {
            return "you have never seen these pills before, it gives you a \nweird feeling, maybe you should'nt take them";
        }
    }

    namespace balcony {
        std::string getText() {
            return "you finally have access to the balcony, your not that far \nfrom the ground, perhaps you should jump? ";
        }
    }

    namespace trainStation {
        std::string getText() {
            return "a zombie almosts attacks and kills you in one sweep! \n good thing you had that knife with you\n wait you picked up the knife right?";
        }
    }

    namespace insideTrain {
        std::string getText(){
            return "pull the leaver and escape.";
        }
    }
}
