// 段家 門人 made by onion
//調整object me=this_player()的判斷 by blazakira 2011/5/20

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string do_story();
string do_give();

void create()
{
  set_name("柳毅風",({"liu"}));
  set("long","柳毅風是段雲的大弟子, 近年來段家的事大約都是由他經手的, "+
    "才智與武功\均屬上等, 為人也謙遜有理, 因此段雲早想將掌門之位相傳了。\n");
  set("gender","男性");
  set("class","scholar");
  set("combat_exp", 300000);
  set("attitude","heroism");
  set("age",45);
  set("inquiry",([
    "左正" : "左正與張冰都是段家掛名的子弟, 這次他們遇上的難題, 便向我們段家求救了",
    "張冰" : "左正與張冰都是段家掛名的子弟, 這次他們遇上的難題, 便向我們段家求救了",
    "sad_story" : (: do_story :),
    "一陽心法秘笈" : (: do_give :),
  ]));
  set("force",1500);
  set("max_force",1500);
  set("force_factor", 5);
  set_skill("force",50);
  set_skill("stabber",80);
  set_skill("unarmed",60);
  set_skill("dodge",60);
  set_skill("sunforce",60);
  set_skill("linpo-steps",60);
  set_skill("six-fingers",90);
  map_skill("force","sunforce");
  map_skill("dodge","linpo-steps");
  map_skill("move","linpo-steps");
  map_skill("parry","six-fingers");
  map_skill("stabber","six-fingers");
  map_skill("unarmed","six-fingers");
  set_temp("apply/dodge",100);
  set("chat_chance_combat", 20);
  set("chat_msg_combat", ({
    (: perform_action("stabber.handwriting") :),
  }));
  setup();
  carry_object(PING_OBJ"fan1")->wield();
  add_money("silver",50);
  create_family("段家",11,"弟子");
}

string do_story()
{
  object me=this_player();
  if( (int)me->query_temp("thief") >= 4)
  {
    me->set_temp("thief",5);
    command("say 師父的往事嗎..其實只有一件事令師父頗為傷心...");
    return ("在二十幾年前, 二師弟趙琴風(chao)正是位英俊少年, 也頗得師父歡心, "+
      "只是二師弟年少輕狂、少不更事, 竟然一時把持不住, 受雲南的妖女所惑"+
      "盜走了六脈神劍的劍譜, 是後雖然二師弟良心發現, 將劍譜追回, 但礙於"+
      "門規, 師父也只好忍痛將二師弟逐出師門, 唉....\n\n"+
      "柳毅風停了一會後說道: 請轉告師父說, 要面對現實了。"); 
  }
  else
    return("傷心..沒有你傷心..傷心..沒有你傷心\n\n柳毅風在大庭廣眾下就唱了起來..哇勒！\n");
}

string do_give()
{
  object note,me=this_player();
  if( me->query("family/family_name") == "段家" )
  {
    if( present("sunforce note",me) )
      return ("你身上不是已經有一本了嗎？\n");
    else{
      note=new(PING_OBJ"sunforce_note");
      if( !note->move(me) )
        note->move(environment(me));
      return ("這本秘笈中記載了一陽心法的一個密招, 是我費盡千辛萬苦才尋回"+
        "來的, 這就麻煩師弟跑一趟, 幫我把這本秘笈交至師父手上了。\n");
    }
  }
  else
  {
    command("? "+getuid(me));
    return ("這好像不關你的事喔。");
  }
}

void die()
{
  object winner = query_temp("last_damage_from");
  int j;

  if(!winner)
  {
    ::die();
    return ;
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj8/bamboo_wind")->move(environment(winner));
        message_vision(HIM + "\n從柳毅風的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj8/bamboo_wind",sprintf("%s(%s) 讓柳毅風掉下了竹傲風於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }else{
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj8/bamboo_wind")->move(environment(winner));
        message_vision(HIM + "\n從柳毅風的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj8/bamboo_wind",sprintf("%s(%s) 讓柳毅風掉下了竹傲風於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  ::die();
}

