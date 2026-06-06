// opem/killer/island/npc/louton.c
inherit NPC;     //魯仝
#include <ansi.h>
#include "/open/open.h"
inherit F_MASTER;
string song1();
string song2();
string dream();
string breakmethod();

void create()
{
set_name("魯先生",({"lu ton","lu","ton"}));
set("long","
魯先生原名魯仝 ,年紀很輕加入黑牙聯 ,聽說當年跟葉孤城十分教好 ,曾一同前往東
瀛聽說其實力不亞於葉孤城 .與葉孤城從東瀛回來之後就封刀不再出任務 ,卻到這裡
掌廚,口中常常哼著一些奇怪的(歌曲) .
\n");
  set("gender","男性"); 
  set("class","killer");
  set("title","老廚師");
  set("attitude","heroism");
  set("age",61);
  set("max_kee",3500);
  set("kee",3500);
  set("max_force",2000);
  set("force",2000);
  set("force_factor",10);
  set("combat_exp",1500000);
  set_skill("dodge",100);
  set_skill("move",100);
  set_skill("force",100);
  set_skill("parry",90);
  set_skill("shade-steps",100);
  set_skill("blackforce",100);
  map_skill("move","shade-steps");
  map_skill("dodge","shade-steps");
  map_skill("force","blackforce");
  set("chat_chance",10);
  set("chat_msg", ({
            ""+HIY+"魯先生低聲哼著: 天剛破曉 ,妳和我倚偎在樹旁的岩石邊 ,欣賞這美麗的黎明美景~~"+NOR+"\n",
            ""+HIY+"魯先生說道: 來來來....要來點什麼嗎?"+NOR+"\n",
               }));
  set("inquiry",([
"歌曲" : (: song1 :),
"歌" : (: song2 :),
"夢想" : (: dream :),
"破浪的方法" : (: breakmethod :),
]));

setup();
add_money("gold",10);
}
void init()
{
add_action("do_report","report");
add_action("do_verify","verify");
}

int accept_kill(object who)
{
  command("say 唉....幹麻欺負老先生呢....");
  return 1;
}
string song1()
{
 object ob;
 object me;
 ob=this_object();
 me=this_player();
if (me->query("class") != "killer" || me->query("quest/island") > 0)
{
  command("?");
  return "你說什麼??";
}
  command("look "+me->query("id"));
  command("say 原來是"+me->query("name")+"啊....自從我到廚房以來,你是第一個問我這個問題的人呢.");
  return "這首(歌)....";
}
string song2()
{
 object ob;
 object me;
 ob=this_object();
 me=this_player();
if (me->query("class") != "killer" || me->query("quest/island") > 0)
{
  command("?");
  return "你說什麼??";
}
tell_object(me,HIY"
魯先生偷偷對你說 :
啊....這首個的背景,已經幾十年沒有人再提起了,沒想到今天再度提起,還是令我感到無比的遺憾.
你們都知道當年我跟葉孤城一同到東瀛吧,這首歌是我跟一位東瀛女子所作的.當年在東瀛,因為任務
的關係,認識了一位東瀛女子.她是一位很有才華又很有見識的女子.當時後的我十分的欣賞她.她是
當地一位海外商人的女兒,由於父親工作的關係,她常常到各地去.我們去東瀛所乘的船,就是他們父
女的商船.當時,我常常跟她一同聊天.你該知道,我們殺手不管在何時,都不該與外人有太多的溝通,
但是,面對她我卻不自主的會想跟她談話.聽她敘述其他國家的特色以及傳說,真是讓當年年輕的我感
到十分的有趣.殺手除了殺戮技巧,還知道其他事物嗎?!從那時候我就覺得...可能我不適合當殺手吧
,因為我並沒有足夠的定性壓抑自己的感情與好奇.老葉了解我的想法,於是就同意我在東瀛的任務完
成之後,離開黑牙聯,讓我到世界各地探索新的事物.
\n"NOR);
 command("sigh");
tell_object(me,HIY"
我們完成任務之後,當我要送老葉離開東瀛時,在海上卻遇到了東瀛的海賊,他們盯上了這艘商船,於
是我們在海上發生了激戰,當時船上只有少數黑牙聯的高手,寡不敵眾,我在那時失去了我的右眼,也
失去了我的最愛,我的(夢想)....
\n"NOR);
 command("inn");
return "當時若不是老葉施展滿天花雨擲金針殺了很多海賊,我看我們早就被剁成肉泥啦,呵呵呵呵....";
}

string breakmethod()
{
 object me= this_player();

  if (me->query("class") != "killer"|| me->query_temp("firstpart") !=3 )
  {
  	command("?");
  	return "你說什麼??";
  }

  tell_object(me,HIY"
『破浪方法？我是不清楚啦，但傳說中，殺手有個(特殊身法)  據說可以操控風吧....
或許\可以利用他來突破神風吧.....但是除了殺手裡面資歷夠老的殺手之外
好像沒有人知道這一個身法的真相，你去找找資歷夠老的殺手問問吧......』\n"NOR);
  me->set_temp("firstpart",4);
  return "殺手的老字號不過就那幾個人，總有人知道(特殊身法)吧.....";
}

string dream()
{
 object ob;
 object me;
 ob=new("/open/killer/island/obj/luamulet");
 me=this_player();
if (me->query("class") != "killer"|| me->query("quest/island") > 0)
{
  command("?");
  return "你說什麼??";
}
if (me->query_temp("get_luamulet") == 1)
  return "還沒找到我兒子嗎??";
  command("sigh");
tell_object(me,HIY"
魯先生緩緩的唱著 : 天剛破曉,妳和我倚偎在樹旁的岩石邊,欣賞這美麗的黎明美景~~
\n"NOR);
tell_object(me,"一曲唱完,魯先生給了我一個護身符,上面寫著怪怪的文字,似乎是東瀛文字.旁邊寫著石田麗子四個漢字.\n\n");
ob->move( this_player() );
me->set_temp("get_luamulet",1);
return "這是當年她送我的定情之物,是一對的....她身上的有寫著我的
            名字,麻煩你拿給楓林港的魯尋,他是我養子,希望他能以此物尋
            回(父親的夢想)!!";
}
int do_report()
{
object me=this_player();
if (me->query("quest/island") > 0)
{
command("smile");
return 1;
}
if (me->query_temp("care") == 1 || me->query_temp("complete")==1 )
{
 tell_object(me,HIW"\n你將事情經過的一切告訴魯仝....\n"NOR);
 command("hmm");
 command("say 快將匕首拿給我看看!!");
 return 1;
}
if (me->query_temp("care") == 2 )
{
 tell_object(me,HIW"\n你將事情經過的一切告訴魯仝....\n"NOR);
 command("sigh");
 command("say 年輕人無法忍受物質的誘惑也是正常的....");
 command("say 不過為了感激你, 我傳授你一些暗器方面的技巧好了!!");
 me->set("quest/island",1);
 me->delete_temp("care");
 command("say 這技巧當你使用千古恨時, 便可以將霸雨螫魂的功\力發揮到淋漓盡致!!");
 return 1;
}
command("?");
return 1;
}
int accept_object( object me , object ob ,object obj )
{
if (me->query_temp("complete") == 1 && ob->query("id") =="old dagger")
{
tell_object(me,HIY"魯仝一見到匕首, 便老淚\縱橫激動的說道:\n"NOR);
tell_object(me,HIY"事隔幾十年, 我終於得到了我長年來的夢想!!年輕人, 真是謝謝你了!!\n\n"NOR);
tell_object(me,HIC"這把匕首, 原來是魯仝最珍惜的隨身武器, 當年魯仝承諾麗子將來願意\n"NOR);
tell_object(me,HIC"捨棄殺戮而與她自由自在遨遊世界時, 便是以這把匕首為信物. 魯仝與\n"NOR);
tell_object(me,HIC"麗子當時年輕的共同夢想完全寄託在這把匕首上. 如今魯仝雖老, 麗子\n"NOR);
tell_object(me,HIC"雖亡, 但是他們的夢想與對彼此的愛, 卻寄託在這把破舊的匕首裡, 直\n"NOR);
tell_object(me,HIC"到永遠....\n"NOR);
command("say 為了感謝你, 我將我所有關於暗器的技巧傳授給你好了!!");
command("say 這技巧當你使用千古恨時, 便可以將霸雨螫魂的功\力發揮到淋漓盡致!!");
command("say 當你需要千古恨時, 可以來跟我索取(verify)!!");
me->set("quest/island",3);
me->delete_temp("complete");
return 1;
}
if (me->query_temp("care") == 1 && ob->query("id") =="old dagger")
{
tell_object(me,HIY"魯仝一見到匕首, 便老淚\縱衡激動的說道:\n"NOR);
tell_object(me,HIY"事隔幾十年, 我終於得到了我長年來的夢想!!年輕人, 真是謝謝你了!!\n\n"NOR);
tell_object(me,HIC"這把匕首, 原來是魯仝最珍惜的隨身武器, 當年魯仝承諾麗子將來願意\n"NOR);
tell_object(me,HIC"捨棄殺戮而與她自由自在遨遊世界時, 便是以這把匕首為信物. 魯仝與\n"NOR);
tell_object(me,HIC"麗子當時年輕的共同夢想完全寄託在這把匕首上. 如今魯仝雖老, 麗子\n"NOR);
tell_object(me,HIC"雖亡, 但是他們的夢想與對彼此的愛, 卻寄託在這把破舊的匕首裡, 直\n"NOR);
tell_object(me,HIC"到永遠....\n"NOR);
command("say 為了感謝你, 我將我所有關於暗器的技巧傳授給你好了!!");
command("say 這技巧當你使用千古恨時, 便可以將霸雨螫魂的功\力發揮到淋漓盡致!!");
command("say 當你需要千古恨時, 可以來跟我索取(verify)!!");
me->set("quest/island",2);
me->delete_temp("care");
return 1;
}
command("?");
return 1;
}
int do_verify()
{
object me,ob;
me=this_player();
if (me->query("quest/island") < 2)
{
command("say 我沒什麼東西可以給你!!");
return 1;
}
if (present("hate knife",me))
{
command("say 千古恨用完再跟我要吧!!");
return 1;
}
if (me->query("quest/island")==3)
{
ob=new("/open/killer/obj/hate_knife");
ob->set_amount(1000);
ob->set("no_drop",1);
ob->set("no_give",1);
ob->set("no_sell",1);
ob->move(me);
command("say 千古恨用完啦??那我再給你吧!!");
return 1;
}
if (me->query("quest/island")==2)
{
ob=new("/open/killer/obj/hate_knife");
ob->set_amount(500);
ob->set("no_drop",1);
ob->set("no_give",1);
ob->set("no_sell",1);
ob->move(me);
command("say 千古恨用完啦??那我再給你吧!!");
return 1;
}
}
