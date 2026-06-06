#include <room.h>
inherit ROOM;
void create()
{
        set ("short", "診療室");
        set ("long", @LONG
走到這裡，看到許多病人病厭厭地坐在椅子上，醫生們走來走去，
只見原本病厭厭的病人，一下子就生龍活虎起來，銀針門醫術天下第一
，果然名不虛傳。往南是銀針門的玄關 (open door)。
LONG);
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"5",                   
        "south":__DIR__"1-door",            
        "east":__DIR__"7",             
        "west":__DIR__"9",            
        ]) );

        set("light_up", 1);
        create_door("south","紅木刻紋大門", "north",DOOR_CLOSED);
   setup();
}


