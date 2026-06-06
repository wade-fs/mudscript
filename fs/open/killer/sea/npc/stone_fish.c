#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("石狗公",({"stone fish","stone","fish"}));
set("long","挖勒。。這不是深海魚嗎？怎麼會跑這裡來了呢？。\n");
set("race","人類");
set("gender","雌性");
set("attitude","heroism");
set("limbs", ({ "頭部", "身體",  "尾巴" }) );
set("verbs", ({ "bite", "claw" }) );
set("age",40);
set("int",30);
set("per",30);
set("str", 30);
set("con", 30);
set("force",300);
set("max_force",300);
set("max_kee",500);
set("kee",500);
set("combat_exp", 20000);
set_skill("dodge",30);
set_skill("parry",30);
setup();
}
