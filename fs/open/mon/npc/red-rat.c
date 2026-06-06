//排版 by blazakira 2011/8/15

inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>

void create()
{
  set_name("紅毛大老鼠", ({ "red rat","red","rat" }) );
  set("race", "野獸");
  set("age", 30);
  set("attitude", "aggressive");
  set("max_gin", 10000);
  set("max_kee", 13000);
  set("max_sen", 10000);
//  set("gin",10000);
//  set("sen",10000);
//  set("kee",13000);
  set("str", 20);
  set("cor", 20);
  set("spi", 20);
  set("int", 20);
  set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
  set("verbs", ({ "bite", "claw" }) );
  set("bellicosity",10000);
  set("max_force",10000);
  set("force",10000);
  set_temp("apply/armor", 100);
  set_temp("apply/defense", 250);
  set_temp("apply/damage", 160);
  set_temp("apply/attack", 160);
  set("force_factor",15);
  set("combat_exp", 4000000);
  set_skill("move",100);
  set_skill("dodge",100);
  set_skill("parry",100);
  set_skill("unarmed",100);
  set_skill("force",100);
  set_skill("rabbit-combat",100);
  map_skill("unarmed","rabbit-combat");
  setup();
}
