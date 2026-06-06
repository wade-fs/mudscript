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
        "north":__DIR__"4",             
        "west":__DIR__"8",             
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/doctor/npc/woman" : 1,
        "/open/doctor/npc/man" : 1,                
]));

   setup();
}

