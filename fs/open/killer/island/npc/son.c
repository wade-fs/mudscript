//open/killer/island/npc/son.c
inherit NPC;     //魯尋
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;
string father_dream();
string island();

void think(object);
void create()
{
set_name("魯尋",({"lu"}));
set("long","
年紀輕輕就是往返東瀛的貿易商人. 除了東瀛之外, 他也時常出海到其他外邦
進行貿易, 是一位十分有能力的年輕人.
\n");
  set("gender","男性"); 
  set("class","killer");
  set("title","貿易商");
  set("attitude","heroism");
  set("age",31);
  set("max_kee",1500);
  set("kee",1500);
  set("max_force",1000);
  set("force",1000);
  set("force_factor",10);
  set("combat_exp",700000);
  set_skill("dodge",70);
  set_skill("move",70);
  set_skill("force",70);
  set_skill("parry",60);
  set_skill("shade-steps",60);
  set_skill("blackforce",60);
  map_skill("move","shade-steps");
  map_skill("dodge","shade-steps");
  map_skill("force","blackforce");
  set("inquiry",([
"父親的夢想" : (: father_dream :),
"東瀛島" : (: island :),
]));

setup();
add_money("gold",10);
}
void init()
{
        add_action("do_nod","nod");
}

string island()
{
 object ob,obj;
 object me;
 ob=this_object();
 me=this_player();
 
if (me->query("class") != "killer"|| !me->query_temp("firstpart") )
{
  command("?");
  return "....你說什麼？....我...不知道";
}
  command("grin");
  command("say 你靠近我，我小聲的告訴你......");
  set_name("東瀛殺手",({"Japan killer","killer"}));
  this_object()->set("combat_exp",1500000);
  this_object()->set("max_force",3800);
  this_object()->set("gin",2000);
  this_object()->set("sen",2000);
  this_object()->set("max_kee",8000);
  this_object()->set("kee",8000);
  this_object()->set("eff_kee",8000);
  this_object()->set("force",3800);
  set_skill("dodge",80);
  set_skill("move",80);
  set_skill("parry",80);
  set_skill("throwing",80);
  set_skill("rain-throwing",70);
  set_skill("shade-steps",85);
  obj=carry_object("/open/killer/obj/lustar");
  obj->add_amount(1000); 
  obj->wield();
  ob->kill_ob(me);
  message_vision(HIR + "$N突然對$n發動攻勢!!!!!\n" + NOR,ob,me);
  return "就憑你也想到東瀛島去，就讓你死在我的手下吧......";
}

string father_dream()
{
 object ob;
 object me;
 ob=this_object();
 me=this_player();
if (me->query("class") != "killer"|| me->query("quest/island") > 0)
{
  command("?");
  return "我父親怎麼了嗎?";
}
  command("scream");
  return "咦? 你怎麼會知道這件事? 我父親給你的護身符能讓我看一下嗎?";
}
int accept_object( object me , object ob ,object obj )
{

if (me->query_temp("get_luamulet") == 1 && ob->query("id") =="luton's amulet")
{
 new("/open/killer/island/obj/luamulet")->move(me);
 command("say 真是麻煩你了,我從十幾年前就開始從東瀛往來,希望能繼承父親的夢想.");
 command("say 但是他始終不肯再告訴我其他的線索....");
 command("say 如今有了這護身符及人名,我一定要找回父親當年所失去的一切!!");
 command("say 你願意助我一臂之力嗎??");
 me->delete_temp("get_luamulet");
 me->set_temp("nod",1);
 return 1;
}
if (me->query_temp("get_note") == 1 && base_name(ob)=="/open/killer/island/obj/note")
{
 command("hmm");
 command("think");
 command("原來如此....");
 tell_object(me,"魯尋慢慢將紙條的內容翻譯給我聽....\n");
 call_out("think",3,me);
 return 1;
}
else
{
 command("angry");
 command("gozila");
 command("dandan "+me->query("id"));
 command("say 不要亂拿東西給我啦!!我的身上是要放錢的!!");
 return 1;
}
}
int do_nod()
{
  object me=this_player();
  if (me->query_temp("nod") != 1)
{
 return 0;
}
  if (me->query_temp("nod") == 1)
{
 command("jump");
 command("say 太好了, 我們走吧!!");
 me->delete_temp("nod");
 tell_object(me,HIC + "\n當一切準備就緒後,我與魯尋及一些船員,一同前往東瀛.\n\n" + NOR);
 me->move("/open/killer/island/ship");
 return 1;
}
return 1;
}
void think(object me)
{
tell_object(me,HIY + "\n
原來,麗子並不是商人的女兒,而是海盜首領的女兒,由於跟著父親到處闖蕩,所以能到各
地探索未知的事物變成了她的心願,可是因為無法忍受父親及其手下凶殘的行為,毅然決
定離開他們而過著自己的冒險生涯,直到遇到了魯仝,終於發現長久以來的夢想終於有人
能跟她一起努力與分享.但是這心願終究無打達成,當魯仝被攻擊時 ,是麗子以回到父親
身為條件而換取海賊的撤退.事隔多年,麗子終於因為東瀛政府對海賊的掃蕩而死於這座
小島上.最後在信中留下了一句:我將你給我的定情物以及我們的夢想藏在屬於我們的歌
曲之中.

然而, 將夢想藏在屬於我們的歌曲之中??這句話是什麼意思呢??
\n" + NOR);
call_out("t1",1,me);
return ;
}
int t1(object me)
{
command("giggle");
command("say 稍微休息一下吧, 船隻大概明天就能修好了.");
call_out("t2",1,me);
return 1;
}
int t2(object me)
{
tell_object(me,"\n經過一天的忙碌, 也該趁現在好好睡一下了....\n\n");
me->move("/open/killer/island/tent.c");
call_out("t3",5,me);
return 1;
}
int t3(object me)
{
tell_object(me,HIY + "
不之過了多久, 天也快亮了, 在你心中總覺得有些事情不對勁, 但是又說不上來...
睡了一段時間, 你想也差不多該起來看看船隻修復進度了. \n" + NOR);
call_out("t4",2,me);
return 1;
}
int t4(object me)
{
me->move("/open/killer/island/is4.c");
command("hi");
command("say 起得真早, 天還沒亮就起來了.");
command("say 船隻快修好了, 你去準備一下吧, 等船隻修好就可以離開了.");
me->set_temp("can_search",1);
return 1;
}

void die()
{
	string head;
	object winner = query_temp("last_damage_from");
	int j;
	if(!winner){
      		::die();
      		return ;
    	}
	
	if ( winner->query_temp("firstpart")==1 )
	{
	  message_vision(HIM + "\n$N仔細端詳了屍體，發現此人居然帶著人皮面具？\n" + NOR,winner);
	  message_vision(HIM + "\n$N心念一轉，莫非魯尋遭到意外？\n" + NOR,winner);
	  message_vision(HIM + "\n$N找了找屍體，並沒有發現任何異樣.....\n" + NOR,winner);
	  message_vision(HIM + "\n$N陷入沉思.........................\n" + NOR,winner);
	  message_vision(HIM + "\n.................................\n" + NOR,winner);
	  message_vision(HIM + "\n東瀛殺手...以前在哪裡出現過呢？.......\n" + NOR,winner);
	  winner->set_temp("firstpart",2);
	}
      :: die();
}

