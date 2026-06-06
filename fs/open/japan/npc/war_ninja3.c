// sparrow.c by oda
// use in /open/center by powell
//改寫為暗殺活動輔助用的npc by blazakira 2011/8/25

inherit NPC;

void create()
{
  set_name("影子", ({ "shadow" }) );
  set("long", "一道淡淡地影子，不知道是何人的。\n");
  set("gender","男性");
  set("age", 20);
  set("combat_exp",80);
  setup();
}
