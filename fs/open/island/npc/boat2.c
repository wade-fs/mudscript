// open/island/npc/boat1.c
#include "/open/open.h"
inherit NPC;
int time=0;
void create()
{
        set_name("小木筏", ({ "boat" }) );

        set("long", @LONG
用木材紮起來的筏子 ,古樸的樣子令人感到
無比的親切 ,風大舟輕 ,大概很快就能夠到
達想去的地方...

LONG);
        set("attitude", "friendly");

        setup();
        set_heart_beat(1);
}
void init()
{
        add_action("do_look","look");
        add_action("do_look","l");
}

void heart_beat()
{
 time++;
 if(time==1)
 {
 say("前往神仙島的渡船到囉 , 請趕快搭(board)船 !\n");
 }
 if(time==11)
 {
 say("出航囉 , 沒搭上的人下次請早 !\n");
 destruct(this_object());
 }
} 

int do_look(string str)
{
        if(str=="boat")
        {
        write("用木材紮起來的筏子 ,古樸的樣子令人感到
無比的親切 ,風大舟輕 ,大概很快就能夠到
達想去的地方...

\n");
        return 1;
        }
return 0;
}
int accept_fight(object me)
{
        return notify_fail("看清楚 , 那並不是生物 !\n");
}
int accept_kill(object me)
{
        return notify_fail("看清楚 , 那並不是生物 !\n");
}


