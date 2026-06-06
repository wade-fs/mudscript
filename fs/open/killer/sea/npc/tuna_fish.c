#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
set_name("金槍魚",({"tuna"}));
set("long","又名鮪魚，這是一種東瀛島桌上常見的魚類，味道極為鮮美\n");
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
set("max_kee",300);
set("kee",300);
set("combat_exp", 7000);
set_skill("dodge",10);
setup();
}
