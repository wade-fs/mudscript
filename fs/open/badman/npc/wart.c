inherit NPC;
void create()
{
  set_name("疣豬",({"wart"}));
  set("long","一頭剛出生的小疣豬,好像和父母走失了....在四處找路\n");
  
  set("race","野獸");
  set("genser","雄性");
  set("age",1);
  set("attitude","peaceful");
  set("limbs",({"頭部","腹部","前腿","尾巴","後腿"}));
  set("verbs",({"bite","claw"}));
  set_skill("dodge",10);
  set("combat_exp",300);
  set("chat_chance",1);
  set("chat_msg",({
       "吼...吼....吼.....\n",
  }));

  setup();
}

void die()
{
      object killer;
      killer=query_temp("last_damage_from");
      killer->set_temp("blood",1);
      message_vision("幾滴鮮血濺到了$N的衣服上。\n",killer);
      ::die();
}

