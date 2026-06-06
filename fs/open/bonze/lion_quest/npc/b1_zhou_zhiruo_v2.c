// 本版本參考/open/capital/npc/sell-officer.c 使用switch函數作為判斷基準 by blazakira
// 增加少林廚藝學院的quest相關 by blazakira 2010/09/07
// 增加少林寺水荒相關線索　by blazakira 2011/3/7

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string ask_time();
string ask_quest();
string ask_water();

object obj1,obj2; //暫定分配為倚天劍 屠龍刀的變數 用來使劇情延續的變數
object bk; //將倚天 屠龍設定為毀壞武器的變數

void create()
{
	set_name("周芷若", ({ "zhou zhiruo", "zhou", "zhiruo", "z" }) );
	set("long","　　烏溜溜的長髮及腰與裸露出雪白晶瑩的雙肩襯出一身高挑姣好的身\n"
              +"材，鮮紅的櫻唇、靈動的雙眼，帶著清純知性美的氛圍讓她擁有一群堅\n"
              +"定的擁護者，是以得罪了她，走在路上就得小心些。\n");
    set("nickname",HIC + "亂" + HIY + "世" + HIM + "妖女" + NOR);
	set("gender", "女性" );
	set("class","swordsman");
	set("combat_exp",1001);
	        set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
//        set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//        set("attitude","aggressive"); //主動攻擊玩家
	set("age", 22);
		set("str", random(7)+19);
		set("cor", random(7)+28);
		set("cps", random(7)+33);
		set("int", random(7)+37);
		set("per", random(7)+35);
		set("kar", random(7)+25);
	set("inquiry",([
		"有效期間"      : (: ask_time :),
		"任務清單"      : (: ask_quest :),
		"任務"          : (: ask_quest :),
		"少林寺水荒"    : (: ask_water :),
		]));
	set("chat_chance", 6);
	set("chat_msg", ({
		"周芷若說道: 聽說小東邪拿著一把利器，真想借來看看。\n",
		"周芷若說道: 聽說有一把刀可以號令天下武林。\n",
		"周芷若說道: 拿到我想要的東西就讓你擁有臨時聯盟成員的身份。\n",
		"周芷若說道: 既然是「臨時」聯盟成員的身份，在【有效期間】內可在駐地裡面接任務。\n",
        }) );
	setup();
/*未開放exp時 先不穿裝備 武器未定
  carry_object("/open/ping/questsfan/obj/diamond_armor")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_belt")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_boots")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_cloak")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_hairpin")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_hands")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_legging")->wear();
  carry_object("/open/ping/questsfan/obj/diamond_skirt")->wear();
*/
// /open/fire-hole/obj/p-pill 毒龍精元 短時+magic spells en的效果 50 (eat pill)
// /open/mon/obj/thousand-nectar 千年花蜜 短時+force 20000 非maxforce (drink nectar)
// /open/clan/area/home/hae_bag 卍乾坤袋卍(Universal bag) 可以裝物品 且可以丟給他人的袋子 目前還沒想到可以裝什麼
//注意 不可使用丟袋子的功能 但是或許可以使用在quest上(大心)
  all_inventory(this_object())->set("no_get",1);
  all_inventory(this_object())->set("no_steal",1);
}

void init()
{
  set_heart_beat(1);
  ::init();
}

int accept_object(object who, object ob)
{
//  object mid; //暫定為給予物品或獎勵的變數 //目前尚未有作用 2010/09/08 by blazakira
  string object_name; //物品的名稱 主要為屠龍刀所使用
  string object_id; //物品的名稱 主要為倚天劍所使用
  object_id=ob->query("id"); //分為兩段函數作判斷
  object_name=ob->query("name"); //分為兩段函數作判斷
  switch(object_id) { //先判斷收到物品的id
  case "et-sword":
       if (who->query("quests/bonze/qualified/temporary")+24*59*60 > time()) { //本時間變數有四個
         say("周芷若說：急什麼，過段時間再來向我證明你的能力，口亨！\n");
         command("drop et-sword"); //因為是有效的倚天劍 所以予以讓玩家保留
     return 1; //因為要保留本武器 所以得跳出本迴圈 避免被下方destruct(ob)刪除
         break;}
       if (!ob->query_temp("quests/bonze/online")) { //本判斷為避免玩家不斷庫存本道具致他人無法解謎所做的限制
         say("周芷若說：我不接受偽劣仿造的次品。\n");
         message_vision("語畢，周芷若隨手扔至一旁的廢鐵堆裡。\n\n",who); //從庫存拿出的刀劍都直接使用最後的物件刪除
         break;}
       command("tsk");
       say("周芷若說：果然是這把倚天劍。\n");
       obj1=who->set_temp("quests/bonze/obj/et-sword",1); //為收到倚天的mark 因為使用set 所以需用物件來儲存函數
       break;
  case "old sword":
       command("sm "+who->query("id"));
       command("sm "+who->query("id"));
       command("sm "+who->query("id"));
       command("sm "+who->query("id"));
       command("sm "+who->query("id"));
       say("周芷若說：拿錯了吧，口亨！什麼鬼玩意。\n");
       command("drop old sword");
     return 1; //因為要保留本武器 所以得跳出本迴圈 避免被下方destruct(ob)刪除
       break;
  default : break;
  }
  switch(object_name) { //判斷收到物品的name
  case HIY + "屠龍刀" + NOR:
       if (who->query("quests/bonze/qualified/temporary")+24*59*60 > time()) {
         say("周芷若說：急什麼，過段時間再來向我證明你的能力，口亨！\n");
         command("drop dragon blade"); //因為是有效的屠龍刀 所以予以讓玩家保留
     return 1; //因為要保留本武器 所以得跳出本迴圈 避免被下方destruct(ob)刪除
         break;}
       if (!ob->query_temp("quests/bonze/online")) { //本判斷為避免玩家不斷庫存本道具致他人無法解謎所做的限制
         say("周芷若說：我不接受偽劣仿造的次品。\n");
         message_vision("語畢，周芷若隨手扔至一旁的廢鐵堆裡。\n\n",who); //從庫存拿出的刀劍都直接使用最後的物件刪除
         break;}
       command("tsk");
       say("周芷若說：好！真不愧\是寶刀屠龍。\n");
       obj2=who->set_temp("quests/bonze/obj/dragon_blade",1); //為收到屠龍的mark 因為使用set 所以需用物件來儲存函數
       break;
  case "屠龍刀":
       command("kick "+who->query("id"));
       command("kick "+who->query("id"));
       command("kick "+who->query("id"));
       command("kick "+who->query("id"));
       command("kick "+who->query("id"));
       say("周芷若說：口亨！竟給我假貨，真不識好歹。\n");
       command("drop dragon blade");
     return 1; //因為要保留本武器 所以得跳出本迴圈 避免被下方destruct(ob)刪除
       break;
  default :
       break;
  }
  if (object_id != "et-sword" && object_id != "old sword" && object_id != "dragon blade") //目前只接受兩把武器
  {
    command("say 口責！想在少林寺後山混，就給我認真點！\n");
    message_vision("說完，周芷若微怒地隨手扔出窗外的垃圾堆裡。\n\n",who); //接受的其他雜物都直接使用最後的物件刪除
  }

  destruct(ob);//交回物品得銷毀並免重複解的可行性的bug 放在此處則所有給予周芷若的物品皆會刪除

//編譯時段錯誤﹕/u/b/blazakira/bonzee/room/npc/b1_zhou_zhiruo.c line 63: Bad assignment ( object vs int ).
//需宣告obj1 obj2 為int變數 而非object變數 才能儲存數字 並作obj1=1 && obj2=1的宣告
//「int」 是用來宣告整數變數 「object」 是用來宣告物件
  if (obj1 && obj2) { //如果obj1 obj2存在 此處設定物件存在 始可呼叫函數
  call_out("broken_wp0",3,who); //3秒後才呼叫函數
  }

  return 1;
}

int broken_wp0(object me)
{
//  object me = this_player();
  if(!me) return 1; //判斷玩家是否待在同一間房間
  if(environment(this_object()) != environment(me)) return 1; //判斷玩家是否待在同一間房間
  message_vision(HIM + "只見周芷若一手舉起" + HIC + "倚天劍" + HIM + "，不停地嘖嘖稱奇。\n" + NOR,me);
  message_vision(HIM + "另一手舉起" + HIY + "屠龍刀" + HIM + "，心中的竊喜掩不住，突然間放聲大笑。\n" + NOR,me);
  message_vision(HIM + "張狂的笑聲令人心驚不已。\n\n" + NOR,me);
  call_out("broken_wp",5,me);
  return 1;
}

int broken_wp(object me)
{
//  object me = this_player();
  if(!me) return 1;
  if(environment(this_object()) != environment(me)) return 1;
  message_vision(HIM + "突然間卻看見周芷若運功\使刀劍互擊。\n" + NOR,me);
  message_vision(HIM + "「鏘—」但見兩把最不可能毀損的刀劍竟然從中斷裂了。\n" + NOR,me);
bk=new("/open/main/obj/broken");
bk->set("name", RED + "(斷毀兩段)" + HIC + "倚天劍" + NOR);
bk->set("id", "et-sword");
bk->move(environment(me)); //me 為給予物品的人物
bk=new("/open/main/obj/broken");
bk->set("name", RED + "(斷毀兩段)" + HIY + "屠龍刀" + NOR);
bk->set("id", "dragon blade");
bk->move(environment(me)); //me 為給予物品的人物
  me->set_temp("quests/bonze/obj/ticket",1); //為完成入門任務所作的標記 //★需改為非temp的mark
message_vision(HIM + "周芷若從斷裂的刀劍中取出兩張字條。\n" + NOR,me);
tell_object(me,"（沒想到刀劍中竟然藏有驚天秘密，你心裡忍不住驚訝，急忙掩著即將脫口而出的驚呼。\n");
tell_object(me,"不過你懷疑下一秒就會被人滅口。）\n");
tell_object(me,"但見她不以為意的抬起頭來看著你，帶著邪惡的笑容對你點了點頭。\n");
  call_out("ticket",6,me);
  return 1;
}

int ticket(object me) //暫定為開始本區的函數
{//我們聯盟的目的就是為了審判金毛獅王謝遜所犯下不可饒恕的大罪
//接下來你可以去找xxx接（任務）來證明你自己了。
//  object me = this_player();
  if(!me) return 1;
  if(environment(this_object()) != environment(me)) return 1;
  if (!me->query("quests/bonze/qualified/forever")) //暫定為永久資格的mark 目前有計畫但是尚未完成 故沒有使用
  {
    command ("say 很好！你已經具有參加我們十大門派滅獅聯盟的臨時資格了。"); //預定為解決謝遜的quest之後才有可能取得永久許可（暫定 但取消的機率高
    command ("say 在持有聯盟成員這一身份的【有效期間】，可以隨時向我詢問【任務清單】。");
    me->set("quests/bonze/qualified/temporary",time()); //臨時資格的mark 為紀錄時間用 預計為一天需要重解一次
    if ( !me->query("quests/bonze/qualified/beggin") ) {
      me->set("quests/bonze/qualified/beggin",1); } //作為 指令：quests 查驗用
  }
  call_out("mission1",4,me);
  return 1;
}

int mission1(object me) //少林廚藝學院的食材任務
{
//  object me = this_player();
  if(!me) return 1;
  if(environment(this_object()) != environment(me)) return 1;  command ("sigh");
  command ("say 雖然我跟臭禿驢很不對盤，不過好歹他也算是一派的掌門，既然他有事要【拜託】，有空你就走一遭吧。");
  me->set_temp("quests/bonze/mission",1); 
  return 1;
}

string ask_time()
{
  object me = this_player();
  if (me->query("quests/bonze/qualified/temporary")+24*59*60 < time())
    return "$N的臨時聯盟成員資格已經失效了。";
  return "$N目前仍是我們的一份子。";
}

string ask_quest()
{
  object me = this_player();
  if (me->query("quests/bonze/qualified/temporary")+24*59*60 < time())
    return "$N的臨時聯盟成員資格已經失效了。"; //資格失效本就問不到任務
  command ("say 目前發布的任務如下：");
  command ("say 1. 少林的禿驢有事要【拜託】。");
  command ("say 2. 聽說某處的三個禿驢相處不太好，需要有人幫忙調解，傳聞其中的獎勵不算太差。");
  me->set_temp("quests/bonze/mission",1); //資格有效期間離線後的補救措施
  return "以上是你的通行證有效期間所能接到最新任務清單。";
}

string ask_water()
{
  object me = this_player();
  if (me->query("quests/bonze/qualified/temporary")+24*59*60 < time())
    return "想跟我接任務，那得先交點東西上來，總該知道我想要什麼吧。";
  command ("say 既然你有資格接任務了，那麼這件事交給你吧。");
  command ("say 據說少林寺裡正在缺水，而且很「嚴重」，有空你可以「常去」幫一下。");
  me->set_temp("quests/bonze/mission",1);
  return "";
}

void die()
{
   object winner = query_temp("last_damage_from");
   string name = winner->query("name");
   string class1 = winner->query("family/family_name");
   tell_object(users(), //winner, 指打死的人 users()指全體玩家
"\n"
HIY + "　　　從少林寺後山傳來一聲嘆息～\n"
"\n"
HIY + "　　　　　三位神僧同聲共念：「阿彌陀佛～」\n"
"\n"
HIM + "　只聞" + HIW + "周芷若" + HIM + "大喊：要不是參透不了" + HIY + "刀" + HIW + "劍" + HIM + "中的秘密，我也不至於敗在"+HIR+class1+HIM + "弟子"+HIR+name+HIM + "手中，\n"
HIM + "　　　　　　　　　我恨…那男人為何不把心放在我身上…\n"
HIM + "　　　　　　　　　我恨…師父為何那樣命令我…\n"
HIM + "　　　　　　　　　我好恨…我好恨上天為什麼這麼不公呀！\n"
"\n"
HIW + "　　　　　　" + HBMAG + "一顆暗沉的帝星散發出刺眼的璀璨光芒後，落入仙劍派的秘境之中。\n" + NOR);
::die();
}
