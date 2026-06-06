inherit NPC;
string eat();
void create()
{
  set_name("少林伙房工",({"kitchen worker","worker"}));
  set("long","他是少林的伙房工，你看他流著汗為少林的僧侶們努力的為所有人煮飯，你可以跟他要吃的(eat)。\n");
  set("gender","男性");
  set("combat_exp",300000);
  set("attitude","peaceful");
  set("age",26);
  set("inquiry",([
    "eat":(:eat:)
  ]));
  set("class","bonze");
  set_skill("unarmed",35);
  set_skill("stick",80);
  set_skill("dodge",60);
  set_skill("parry",60);
  set("chat_chance",10);
  set("chat_msg",({
  }));
  setup();
  add_money("silver",8);
  carry_object("/open/bonze/obj/club")->wield();
}

string eat()
{
  object me = this_player();
  if(me->query("class") != "bonze")
    return "對不起，這裡只提供齋菜給師父哦！ ";
  if(me->query_temp("need_food")+15*60*60 > time())
    return "剛已經拿給你了，這裡有很多人還要吃呢，你等等再來。";
  me->set("food",me->max_food_capacity());
  me->set("water",me->max_water_capacity());
  me->set_temp("need_food",time());
  return "來吧，這些是$N要吃的齋菜，$N就慢慢吃吧。";
}
