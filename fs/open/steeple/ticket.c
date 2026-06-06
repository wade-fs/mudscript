#include <ansi.h>
inherit ROOM;
void create ()
{
set("short", HIW + "試煉之塔--售票大廳" + NOR);
set("long", @LONG

一堆奇裝異服的人在此處來往走著，甚至還有一些狗頭人身的『人』在此地
與其他『無法形容』的生物交談著，在加上一堆超現在化科技設備呈現眼前
，機器人、液晶顯示版、自動系統....等等，你突然覺得你來到了一個不同
的空間，難道這是在作夢嗎？

右邊有一塊規則版(rule_sign)，左邊一套晶片申請系統(Electornic chip)。

LONG);
set("item_desc",([
"rule_sign":HIW + "
			試煉塔挑戰賽：

規則一：裡面被NPC打死了，會呈暈眩狀態回到recall地方。（感謝SWY大大的苦心編輯）

規則二：如果玩家自己在裡面PK的話，死了恕主辦人不負這個責任。

規則三：挑戰規則是需打倒每一層把關者才能再繼續前進，若已經有人在你
	之前闖關的話，那就請等等再進去。

規則四：闖關的獎品，請到右邊的領獎處索取。

規則五：打完時，必須更新晶片，否則晶片的檔案會與系統不合。

				主辦人	Firedancer@F.S.
" + NOR,
"chip":HIW + "目前是試驗階段，一切晶片免費，請打apply chip申請登記挑戰。

	更新晶片打apply newdata。

	想看某一個人的戰績的話，請輸入list <IP>。

	目前尚不開放塔主名單。

				主辦人  Firedancer@F.S
\n" + NOR,
]));
set("exits",([
"out":__DIR__"steeple",
//"east":__DIR__"prize",
"enter":__DIR__"up00",
"north":__DIR__"nick",
]));
set("no_fight",1);
set("no_die_room",1);
set("no_magic",1);
set("no_transmit",1);
set("objects",([
__DIR__"ticket_robot":1,
]));
setup();
}


int valid_leave(object me,string dir)
{
 if(dir=="out"||dir=="east"||dir=="north")
   {
   me->delete_temp("fighting_apply");
   return 1;
   }
 if(dir=="enter")
   {
   me->delete_temp("fighting_apply");
   if(!present("fight_card",me))
     {
     tell_object(me,HIW + "系統：物件掃瞄，找不到晶片，進入失敗。\n" + NOR);
     return 0;
     }
   if(!me->query("quest/start_game"))
     {
     tell_object(me,HIW + "系統：人體掃瞄，找不到檔案，進入失敗。\n" + NOR);
     return 0;
     }
   return 1;	
   }
}

void init()
{
	add_action("do_apply","apply");
	add_action("do_list","list");
}

int do_apply(string str)
{
int i=(random(10)+1);
object me=this_player();
if(!str||str != "chip")
{
if(str!="newdata")
return notify_fail(HIW + "系統：請確定申請的目標？\n" + NOR);
{
if(me->query_temp("change_time"))
return notify_fail(HIW + "系統：尚在更新檔案，請稍後。\n" + NOR);
{
me->set_temp("change_time",1);
call_out("change_card",i,me);
message_vision(HIW + "系統：開始進行資料更新。\n" + NOR,me);
me->start_busy(i);
message_vision(HIW + "資料傳輸緩衝時間： "+i+" 秒\n" + NOR,me);
return notify_fail(HIW + "系統：開始接收"+me->query("name")+"檔案。\n" + NOR);
return 1;
}
}
}
if(me->query_temp("fighting_apply"))
return notify_fail(HIW + "系統：系統尚在確認中，請耐心等待。\n" + NOR);
if(me->query("quest/start_game"))
return notify_fail(HIW + "系統：申請手續已辦過，請勿再申請。\n" + NOR);
else
{
message_vision(HIW + "系統：申請手續中請勿走動。\n" + NOR,me);
message_vision(HIW + "系統：Id『"+me->query("id")+"』申請確認中，請稍待"+i+"秒。\n" + NOR,me);
me->set_temp("fighting_apply",1);
call_out("check_time",i,me);
return 1;
}
}

int check_time(object me)
{
if(present("fight_card",me))
{
me->delete_temp("fighting_apply");
tell_object(me,HIW + "系統：請勿拿著別人的晶片申請。\n" + NOR);
return 1;
}
if(!me->query_temp("fighting_apply"))
{
tell_object(me,HIW + "系統：目標移動，資料錯誤，申請失敗。\n" + NOR);
return 1;
}
else
{
tell_object(users(),

HIY + "歡迎"+me->query("name")+"加入挑戰" + HIG + "『" + HIR + "試煉塔" + HIG + "』" + HIY + "的行列
		
		" + HIW + "希望"+me->query("name")+"能不負眾望，勇闖第一百層" + HIG + "『" + HIY + "天閤" + HIG + "』" + HIW + "。
" + NOR);
new(__DIR__"f_card")->move(me);
tell_object(me,"你得到了一個晶片。\n");
me->set("quest/start_game",1);
me->delete_temp("fighting_apply");
return 1;
}
}


int change_card(object me)
{
if(!me->query("quest/start_game"))
{
tell_object(me,HIW + "系統：系統找不到你的資料，請重新進行申請。\n" + NOR);
me->delete_temp("change_time");
return 1;
}
if(!present("fight_card",me))
{
tell_object(me,HIW + "系統：抱歉，你的晶片不見了，請先補發吧。\n" + NOR);
me->delete_temp("change_time");
return 1;
}
else
{
destruct(present("fight_card",me));
new(__DIR__"f_card")->move(me);
call_out("send_card",1,me);
return 1;
}
}

int send_card(object me)
{
message_vision(HIY + "系統：開始傳送物件『"HIW+me->query("name")+"晶片" + HIY + "』。\n" + NOR,me);
message_vision(HIY + "\n\n系統遠距離傳送『" + HIR + "轉換器" + HIY + "』預備完成！目標『"HIW+me->query("name")+HIY"』確認。\n" + NOR,me);
message_vision(HIW + "\n\n$N被一道鐳光照射。\n\n" + NOR,me);
tell_object(me,HIW + "你拿到了一片『"+me->query("name")+"晶片』\n" + NOR);
me->delete_temp("change_time");
me->set_temp("apply_newdata",1);
return 1;
}

int do_list(string arg)
{
object me=this_player();
object ob;
ob = LOGIN_D->find_body(arg);
if(!ob)
return notify_fail(HIW + "系統：查詢失敗，此人目前不在線上。\n" + NOR);
else
{
int i=ob->query("quest/start_game");
int a=i-1;
int j=ob->query("quest/lose_game");
tell_object(me,"
 
" + HIW + "▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏
▕▕▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▏▏
▕▕                      火神舞『超級系統查詢機 』                         ▏▏
▕▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏▏
▕▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▏" + NOR + "


		   名字："HIW+ob->query("name")+NOR"

		   幫派："NOR+ob->query("clan/name")+NOR"

		   師傅："NOR+ob->query("family/master_name")+NOR"

		   目前挑戰樓層：第 "HIY+i+NOR" 樓

		   目前登記失敗次數： "HIY+j+NOR" 次
	");
return 1;
}
}
