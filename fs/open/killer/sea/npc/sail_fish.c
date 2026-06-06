#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("旗魚",({"sailfish","fish"}));
set("long","另類的海中霸主，巨大得身軀，令你很難相信這是你一般時候吃的魚\n");
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
set("max_kee",700);
set("kee",700);
set("combat_exp", 70000);
set_skill("dodge",80);
setup();
}
