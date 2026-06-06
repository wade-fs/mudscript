#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set("title","海中霸主");
set_name("鯊魚",({"fish"}));
set("long","恐怖的海中生物，它的尖牙足以撕爛你的身軀\n");
set("race","人類");
set("gender","雌性");
set("attitude","aggressive");
set("limbs", ({ "頭部", "身體",  "尾巴" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",99);
set("int",20);
set("per",20);
set("str", 99);
set("con",20);
set("force",500);
set("max_force",500);
set("max_kee",900);
set("kee",900);
set("combat_exp",80000);
set_skill("dodge",50);
setup();
}
