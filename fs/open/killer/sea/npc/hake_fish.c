#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("鱈魚",({"hake"}));
set("long","一種可食用的魚類，據說在殺手有人拿他來做魚絲，號名鱈魚香絲\n");
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
set("max_kee",200);
set("kee",200);
set("combat_exp", 800);
setup();
}
