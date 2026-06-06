inherit NPC;

void create()
{
  set_name("大疣豬",({"big wart","big","wart"}));
  set("long","一頭相當巨大的母疣豬,眼中卻充滿了焦急的神情,看來可能是和牠心愛的兒子走失了...\n");
  set("race","野獸");
  set("gender","雌性");
  set("age",9);
  set("attitude","peaceful");
  set("limbs",({"頭部","腹部","前腿","尾巴","後腿"}));
  set("verbs",({"bite","claw"}));

  set_skill("dodge",50);
  set_skill("parry",60);
  set_temp("apply/armor",60);
  set_temp("apply/attack",80);
  set("combat_exp",12500);
  
  set("chat_chance",1);
  set("chat_msg",({
      "吼....吼.....吼......\n"
  }));
  setup();
}

void init()
{
      object me=this_player();
      ::init();
      if( me->query_temp("blood")==1 )  {
      message_vision("大疣豬一聞到$N身上的血腥味,便衝動地認為$N對牠寶貝兒子做了 什麼事,一聲怒吼,便撲向$N.\n",me);
      this_object()->kill_ob(me);
      }
}
