#include <ansi.h>

inherit NPC;

string do_ask();

void create()
{
      set("title","六婆");
      set_name("瘦婦人",({"thin woman","thin","woman"}) );
      set("long",@LONG
一個身材削瘦的婦人，卻有一雙刻薄的眼睛，和胖婦人號稱是街上的最佳拍檔，
其潑婦罵街的本事也是當仁不讓於胖婦人的。
LONG
      );
      set("age",49);                 
      set("attitude","peaceful");
      set("gender","女性");

      set_skill("dodge",30);
      set_skill("unarmed",35);
      set_skill("parry",25);
      set("combat_exp",1000);

      set("chat_chance",4);
      set("chat_msg",({
      "瘦婦人笑道:喔!這樣子啊,呵.....\n",
      "瘦婦人笑道:那個明月啊,聽說還想在這做一番大事業呢!呵....\n",
      }) );      

      set("chat_chance_combat",9);
      set("chat_msg_combat",({
      "瘦婦人冷笑道:既然那麼想死,老娘就送你一程吧。\n",
      "瘦婦人冷諷說:小子,你是怕活太久會當米蟲,是不是?我看有可能喔!!\n",
      }) );
  set("inquiry",([
  "杜殺的左手" : (: do_ask :),
  ]));

      setup();

      carry_object("/obj/cloth")->wear();
      add_money("silver",2);
}

int accept_fight(object who)
{
      write("瘦婦人豎起中指挖了挖耳朵。\n");
      switch( random(2) ) {
       case 0: say ("瘦婦人嘆道:年紀輕輕便要夭折,唉~~可惜啊。\n");break;
       case 1: say ("瘦婦人喝道:"+RANK_D->query_rude(who)+"!老娘就陪你玩玩,讓你瞧瞧老娘的手段。\n");break;
  return 1;
      }
  return 1;
}
string do_ask()
{
  int me;
  object who = this_player();
    if(who->query_temp("marks/hand")!=1)
  {
    return "怎麼不問問杜殺呢 ?\n";
  }
  else
  {
  who->set_temp("marks/hand_again",1);
       return "唉呦 !被罵啦..好可憐的小兄弟呀 !沒關係 ,杜殺只是不想欠你人情而已 ,再試一次看看..他應該會跟你說明的 .\n";
  }
}
