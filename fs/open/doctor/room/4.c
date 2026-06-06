#include <room.h>
inherit ROOM;
void create()
{
        set("short","診療室");
        set("long", @LONG

    牆上兩幅斗大的書法字寫著「醫者大忌殺齪」，「二忌見死不救」
，你不由得欽佩華陀的行醫風範，平時他以愛心教導門徒，更重視以德
服人。

LONG
        );        set("exits", ([ /* sizeof() == 3 */
        "south":__DIR__"7",            
        "north":__DIR__"1",             
        "west":__DIR__"5",             
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/doctor/npc/patient" : 1,        
]));

   setup();
}


