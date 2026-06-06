//調整斷行錯誤 by blazakira 2010/12/22

inherit NPC;
void create()
{
  set_name("村姑",({"woman"}));
  set("title","魔界村居民");
  set("gender","女性");
  set("age",27);
  set("str",35);
  set("cor",45);
  set("cps",25);
  set("int",15);
  set("long","魔界村的普通村姑, 正跟人在閒聊著.\n");
  set("combat_exp",350);
  set("attitude", "peaceful");
  set("chat_chance", 25);
  set("chat_msg", ({
    "村姑: 千年冰蟾所散發的毒氣劇烈無比, 沒人能\(進入洞穴)裡.\n",
    "村姑: 聽說旅社二樓的姑娘，似乎有什麼冤屈，整天都說要(討伐)，真奇怪。\n",
    "村姑: 聽說(三葉仙蘭)百年開花一次, 一刻鐘內結果, 再一刻鐘果實爆裂.\n",
    "村姑: 聽說妖魔古塔裡裝有有毒暗器, 進去的沒有人能回來過.\n",
    (: this_object(),"random_move" :),
  }) );
  set_skill("parry", 15);
  set_skill("dodge", 5);
  setup();
}
