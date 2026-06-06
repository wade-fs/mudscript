inherit NPC;     //魯尋
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;
string father_dream();

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
]));

setup();
add_money("gold",10);
}
void init()
{
        add_action("do_nod","nod");
}
string father_dream()
{
 object ob;
 object me;
 ob=this_object();
 me=this_player();
if (me->query("class") != "killer")
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
 new("/u/u/unfinished/room/obj/luamulet")->move(me);
 command("say 真是麻煩你了,我從十幾年前就開始從東瀛往來,希望能繼承父親的夢想.");
 command("say 但是他始終不肯再告訴我其他的線索....");
 command("say 如今有了這護身符及人名,我一定要找回父親當年所失去的一切!!");
 command("say 你願意助我一臂之力嗎??");
 me->delete_temp("get_luamulet");
 me->set_temp("nod",1);
 return 1;
}
if (me->query_temp("get_note") == 1 && base_name(ob)=="/u/u/unfinished/room/obj/note")
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
 me->move("/u/u/unfinished/room/ship");
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
tell_object(me,"經過一天的忙碌, 也該趁現在好好睡一下了....\n");
me->move("/u/u/unfinished/room/tent.c");
return 1;
}
