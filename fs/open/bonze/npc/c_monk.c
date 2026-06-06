inherit NPC;
void create()
{
  set_name("少林棍法僧",({"club monk","monk"}));
  set("long","一個少林的和尚，拿著齊眉棍汗流雨下的練功\。\n");
  set("gender","男性");
  set("combat_exp",300000);
  set("attitude","peaceful");
  set("age",26);
  set("class","bonze");
  set_skill("unarmed",35);
  set_skill("stick",80);
  set_skill("dodge",60);
  set_skill("parry",60);
  setup();
  add_money("silver",8);
  carry_object("/open/bonze/obj/club")->wield();
}
