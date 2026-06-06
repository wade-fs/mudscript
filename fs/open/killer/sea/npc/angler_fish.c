#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("琵\琶魚",({"angler"}));
set("long","大珠小珠落玉盤，猶抱琵\琶半遮面就是用這種魚。。\n呵呵。。。不是啦，這是一種海中魚類\n");
set("race","人類");
set("gender","雌性");
set("attitude","heroism");
set("limbs", ({ "頭部", "身體",  "尾巴" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",20);
set("int",30);
set("per",30);
set("str", 25);
set("con", 30);
set("force",250);
set("max_force",50);
set("max_kee",180);
set("kee",180);
set("combat_exp", 700);
setup();
}
