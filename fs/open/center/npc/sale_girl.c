// /open/center/npc/vendor.c
#include <obj.h>
#include <ansi.h>
#include "/open/open.h"

inherit F_VENDOR;
string ask_test();
string ask_standby();

void create()
{
      set_name("賣火柴的小辣妹", ({ "sale girl", "girl" }) );
      set("nickname","小辣椒")

;
        set("gender", "女性" );
        set("age", 18);
        set("long", @LONG
  一個在狂想空間賣花賣了七年多的小女孩, 終於慢慢長大,
變成亭亭玉立的小辣妹, 噴火的身材異於尋常人，因此, 還
是經常被路過的有錢大爺欺負。由於沒有玩家要跟她買花, 
她至今最大的心願, 還是在這寒冷的冬天有一件衣服穿, 不
過, 沒有衣服的話, 玩家會更高興吧, 所以, 她只好一直在
FS賣花下去囉....
    最近她正在徵求代替(standby)她賣花的好心人......

LONG);
        set("attitude", "friendly");
        set("rank_info/respect", "小妹妹");
        set("combat_exp",180);

        set("vendor_goods", ({
            CENTER_OBJ"torch",
            CENTER_OBJ"map",
        }) );

        set("chat_msg", 5);
        set("chat_msg", ({
           "小辣妹說道: 誰能給我衣服穿啊，好冷耶。\n",
           "小辣妹拉拉你的衣服,眼角閃著淚\光說道: 您能給我一件衣服嗎?\n",
           "小辣妹可憐兮兮的說道: 冬令救濟一下嘛!。\n",
           "小辣妹哀求地說道: 能不能代替(standby)我賣花啊？\n",
        }) );
set("inquiry",([
   "試煉印記" : (:ask_test:),
   "standby" : (: ask_standby :),
      ]));



        set("greeting_msg", ({
         "小辣妹說道: 好心的大爺小姐們，買把木頭當材燒吧。\n",
         "小辣妹可憐兮兮的瞧著你: 這位好心的大爺小姐，伸伸援手救助我吧。\n",
         "小辣妹有氣無力的說: 好心的大爺小姐，路過此地，難道見死不救嗎?\n",
         "小辣妹哀求地說道: 能不能代替(standby)我賣花啊？\n",
        }) );
        setup();
}

int accept_object(object who, object ob)
{      
  object        me;

  seteuid(getuid());
  me = this_object();

  if (who->query("quests/sale_girl") == 0) {
    message_vision("小女孩說道: 謝謝$N賞賜。妹妹我無以為報，賣得的一百文錢"
        "以及賣剩的一把木頭跟一張地圖就當成回報，請您笑納。\n",who);
    who->pay_player(100);
    who->set("quests/sale_girl",1);
    new(CENTER_OBJ"torch")->move(who);
    new(CENTER_OBJ"map")->move(who);
    who->save();
    return 1;
  }
  else {
    message_vision("小女孩說道: 謝謝$N賞賜。\n",who);
    return 1;
  }
}                                                                       

string ask_test()
{
 if(this_player()->query("quests/yan")==3)
 {
  if(this_player()->query("quests/sale_girl",1) && this_player()->query("quests/yantestmark1",1) && this_player()->query("quests/2ndtest",1))
  {
  int i;
  i=6+random(5);
  command("say 謝謝您的幫忙.我願意將appo給我的印記傳到你身上!\n");
  tell_object(this_player(),HIW"瞬間由賣火柴的小辣妹將手搭在你的肩上..你頓時覺得一股暖意由小辣妹的手中傳過來\n"NOR);
  this_player()->set("quests/2ndtest",i);
  this_player()->set("quests/yantestmark2",1);
  return("最後一個印記在聖賢書手上,你可以去找他問問了\n");
  }
 else if (this_player()->query("quests/yantestmark2")>1)
  return ("我已經把印記給你了..你還要做什麼\n");
 else
  return ("救助救助我..我就跟你說印記在哪\n");
 }
else
 return ("啥印記..你在說什麼?\n");
}

string ask_standby()
{
  string *places = ({
    "/open/firedancer/t01.c",
    "/open/hall/way1.c",
    "/open/killer/room/r1.c",
    "/open/killer/room/ru3.c",
    "/open/marksman/room/shop.c",
    "/open/newhand/newhand.c",
    "/open/port/room/port.c",
    "/open/bonze/room/big.c",
    "/open/start/room/f1.c",
    "/open/tensan/room6.c",
    "/open/wu/room/luroom1.c",
    "/open/badman/room/s2.c",
    "/open/capital/room/r01.c",
    "/open/doctor/room/r4.c",
    "/open/gblade/room/c2.c",
    "/open/heaven/castle/room/n5.c",
    "/open/love/room/room2-14.c",
    "/open/mogi/castle/room10.c",
    "/open/mogi/village/room/room-07.c",
    "/open/prayer/room/happy.c",
    "/open/beggar/room/room01.c",
    "/open/center/room/r10.c",
    "/open/evil-area/e01.c",
    "/open/island/room/i1.c",
    "/open/magic-manor/manor04.c",
    "/open/mon/hole.c",
    "/open/ping/room/f2.c",
    "/open/snow/room/hole.c",
    "/open/tailong/room/d3.c",
    "/open/wind-rain/43.c",
    "/open/biau/room6.c",
    "/open/dancer/room/roome2.c",
    "/open/fire-hole/f-48.c",
    "/open/gsword/room/froad2.c",
    "/open/poison/room/room10.c",
    "/open/scholar/room/wind_s.c",
    "/open/soldier/room/r36.c",
    "/open/tendo/room/r3.c"
  });
//2002-12-30 修改-- by kalin 
  if (this_player()->query("got_newbie_standby") < 3 && this_player()->query("combat_exp")<1000000 && (this_player()->query("combat_exp")>2500 || time()-this_player()->query_temp("login_time")>1800))
  {
    if (this_player()->query("standby") < 1) {
    this_player()->add("standby", 1);
    this_player()->add("got_newbie_standby", 1);
    log_file("newbie_stdby", sprintf("%s(%s) ask girl about standby at %s\n"
    ,this_player()->query("name"),this_player()->query("id"), ctime(time()) ));
    this_player()->move (places[random(sizeof (places))]);
    return "say 謝謝您的幫忙, 我願意以身相許\!\n";
    }
    else {
    this_player()->move (places[random(sizeof (places))]);
    return "say 你這個貪心的傢伙，人家不理你了啦。\n";
    }
  }
  else
  {
	return "很抱歉，你的條件不符，我不能幫你。";
  }
}
