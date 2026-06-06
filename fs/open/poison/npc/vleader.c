//2003新增poisoner 的evil-poison之謎
#include <ansi.h>
inherit NPC;
string do_ep1();
string do_ep2();

void create()
{
    set_name("村長",({"village leader","leader"}) );
    set("gender","男性");
    set("age",47);
    set("str",25);
    set("con",22);
    set("max_kee",440);
    set("max_gin",400);
    set("max_sen",350);
    set_skill("dodge",30);
    set_skill("unarmed",30);
    set_skill("parry",30);
    set("combat_exp",10000);
    set("long","
本村的村長，一位樂善好施的人，生性最喜替人排解糾紛，你有甚麼問題
僅管向他開口，想必他一定會盡力幫忙(help)的。\n");
    set("chat_chance", 15);
    set("chat_msg", ({
    "村長皺了皺眉說道:那些該死的強盜。\n",
    "村長憂愁的說道:那些黑風寨的畜生不知會不會來犯。\n",
}) );
    set("inquiry",([
    "help" : "唉~~~(他的表情看來他比你還需要幫助。)\n"
    +"        希望將軍能平安無事，這樣村子的安全才有保障。\n",


    "強盜"     : "要不是有將軍在，這裡只怕早已被洗劫一空了。",
    "將軍"     : "只要有將軍在此保護，黑風寨的人絕不敢來此撒野。",
    "黑風寨"   : "那是那群強盜的棲身之所，聽說是蓋\在山中，但詳細地點我也不清楚。\n",
    "落腳"     : "你說那個老人嗎?他也是個可憐人啊，聽說他以前是冥蠱魔教的「蠱毒長老」。\n",
    "蠱毒長老" : (: do_ep1 :),
    "亂子"     : (: do_ep2 :),

]) );
    setup();
    add_money("silver", 5);
    carry_object("/obj/cloth.c")->wear();
}


string do_ep1()
{
  object me=this_player();
  if(me->query("class")=="poisoner")
  {
  me->set_temp("quest-e",1);
   return("喔, 你說蠱毒長老嗎??就是負責記載蠱物的書記官。
           聽說蠻受前任魔教教主的信任, 只是好像在幾年前的
           一次施蠱過程中, 發生了一些「亂子」, 詳情我不知
           道, 只是看他瘋瘋癲癲的, 就把他收留下來了。\n");
   }
   else return("反正你不是魔教中人, 別問了唄....\n");
}


string do_ep2()
{
  object me=this_player();
  if(me->query("class")=="poisoner" && me->query_temp("quest-e")==1)
  {
   me->set_temp("quest-e",2);
   return("這亂子我可不知道, 可能要問問魔教中人才知道吧。\n");
   }
   else if(me->query_temp("quest-e")==2)  return("你問過了吧....\n");
    else return("亂子??我沒根隔壁的張二娘亂來喔, 別瞎說....\n");
}
