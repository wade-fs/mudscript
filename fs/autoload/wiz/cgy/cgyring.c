#include <command.h>
#include <net/daemons.h>
#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
inherit FINGER;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

void create() 
 {
  set_name(HIY+"神龍之戒"+NOR, ({"ring"}));
  set("long",@LONG
    這是神龍莊主傅劍寒的隨身配備，也是像徵神龍山莊威信的寶物。相傳可招喚法
力無邊的神龍相助，可說是傅劍寒的究極法寶。
LONG);
  set_weight(50);
  set("unit", "只");
  seteuid(getuid());
  set("value",10000);
  set("armor_type","ring");
  set("material","steel");
          if( clonep() )
                set_default_object(__FILE__);
        else {
		 set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
	/*	set("value",2000);      */
		set("material","gold");
		 }
		setup();
  set("armor_prop/armor",30);
  
}
 
void init()
{
  if(environment(this_object())->query("id")=="cgy")
  {
    add_action("do_chat","hzx");
    add_action("do_chat1","mirror");
    add_action("do_chat2","sula");
    add_action("push_doing","push");
    add_action("do_snop"    , "snop");
    add_action("do_fire"    , "fire"); 
    add_action("do_summon"  , "summon");
    add_action("do_shutdown", "shutd");
	add_action("do_nd", "snd");
	add_action("do_unsuck", "uns");
	add_action("do_kkk", "wwar");
	add_action("do_kk", "warr");
      }
}

int do_chat(string str) {
        object me;
        me = this_player();
        if(me->query("id") != "cgy")
           return notify_fail("你想作什麼?\n");
        if(!str) return notify_fail("請說點話吧!\n");
        shout(HIC+"\n【閒聊】黃雲(hzx)說道: "HIC+str+"\n"NOR);
        tell_object(me,HIC+"\n【閒聊】黃雲(hzx)說道: "HIC+str+"\n"NOR);
        return 1;
}
int do_nd(string str){
object me;
me = this_player();
if(!str) return notify_fail("你想做啥!\n");
if(str=="on"){me->set_temp("netdead",1);}
if(str=="off"){me->delete_temp("netdead");}
return 1;
}
int do_unsuck(string str){
object me;
me = this_player();
if(!str) return notify_fail("你想做啥!\n");
if(str=="on"){me->set_temp("unsuck",1);}
if(str=="off"){me->delete_temp("unsuck");}
return 1;
}
int do_chat1(string str) {
        object me;
        me = this_player();
        if(me->query("id") != "cgy")
           return notify_fail("你想作什麼?\n");
        if(!str) return notify_fail("請說點話吧!\n");
        shout(HIC+"\n【閒聊】藏鏡人(mirror)說道: "HIC+str+"\n"NOR);
        tell_object(me,HIC+"\n【閒聊】藏鏡人(mirror)說道: "HIC+str+"\n"NOR);
        return 1;
}
int do_chat2(string str) {
        object me;
        me = this_player();
        if(me->query("id") != "cgy")
           return notify_fail("你想作什麼?\n");
        if(!str) return notify_fail("請說點話吧!\n");
        shout(HIC+"\n【閒聊】復活邪神(sula)說道: "HIC+str+"\n"NOR);
        tell_object(me,HIC+"\n【閒聊】復活邪神(sula)說道: "HIC+str+"\n"NOR);
        return 1;
}
int do_kkk(string arg)
{  object me;
   int i;
   i=random(3);
   me = this_player();
   if(me->query("id") != "cgy")
           return notify_fail("你想作什麼?\n");
   if(arg=="on")
   {
   shout(
HIG"南方三霸"HIM"狂笑道：\n"+
                          HIY"隱居南蠻苦練數載，今日應是我們報仇的時刻到了！哈哈哈！！！\n\n"+
						  "\t\t\t\n\n"NOR);
if (i==0)
{
new("/open/dancer/npc/wind-fighter")->move("/open/ping/room/road4");
new("/open/dancer/npc/wild-blader")->move("/open/main/room/maiu-2");
new("/open/dancer/npc/fly-dancer")->move("/open/prayer/room/westarea/road25");
}
else if (i==1)
{
new("/open/dancer/npc/wind-fighter")->move("/open/main/room/maiu-2");
new("/open/dancer/npc/fly-dancer")->move("/open/ping/room/road4");
new("/open/dancer/npc/wild-blader")->move("/open/prayer/room/westarea/road25");
}
else 
{
new("/open/dancer/npc/wind-fighter")->move("/open/prayer/room/westarea/road25");
new("/open/dancer/npc/fly-dancer")->move("/open/main/room/maiu-2");
new("/open/dancer/npc/wild-blader")->move("/open/ping/room/road4");
}
}
   return 1;
}
int do_kk(string arg)
{  object me;
   me = this_player();
   if(me->query("id") != "cgy")
           return notify_fail("你想作什麼?\n");
   if(arg=="on")
   {
   shout(HIG"\n狂想空間北邊關卡附近傳來一聲淒慘的哀嚎聲\n\n"+
HIR"鎮國侯奄奄一息的說道：\n\n"+
                             "臣鎮守邊關數十年，誓死保衛國家太平\n"+
                             "如今邊關被破，臣有負皇上重託，唯有一死以謝天下\n\n"+
HIY"神秘劍客冷笑道：\n"+
                          HIC"流放邊疆數十年，如今讓我們重回中土，看來天下又要大亂了！哈哈哈！！！\n\n"+
						  "\t\t\t\n\n"NOR);
new("/open/dancer/npc/knight")->move("/open/main/room/r10");
   new("/open/dancer/npc/knight")->move("/open/main/room/s17");
   new("/open/dancer/npc/knight")->move("/open/main/room/r4");
   }
   return 1;
}
int do_kkk2(object me)
{
   message( "system",HIW+"邊關的烽火臺升起了陣陣的狼煙。\n"+NOR, users());
   call_out("do_kkk3",2,me);
   return 1;
}
int do_kkk3(object me)
{
   message( "system",HIC+"神秘劍客突破邊防進入中原了。\n"+NOR, users());
   new("/open/dancer/npc/knight")->move("/open/main/room/r10");
   new("/open/dancer/npc/knight")->move("/open/main/room/s17");
   new("/open/dancer/npc/knight")->move("/open/main/room/r4");
   return 1;
}
int push_doing(string arg)
 {
   if(arg != "down")
   message_vision("$N按下了通知器發出訊息。\n",this_player());
   message( "system",HIY+"你發現傅劍寒突然騎著五爪金龍出現在半空中。\n"+NOR , users() );
   message( "system",HIW+"只見傅劍寒唸了一句 撒拉 伊克 庵修姆。\n"+NOR, users());
   message( "system",HIG+"你忽然覺得精神百倍，信心大增。\n"+NOR, users());
   return 1;
}
int do_snop(string arg)
{
  object ob,me;
  me=this_player();
  if( !arg ) 
  {
    if( objectp(ob = query_snooping(me)) )
      write("你現在正在監聽" + ob->query("name") + "所收到的訊息。\n");
    return 1;
  } 
  if( arg=="none" ) 
  {
    if( objectp(ob = query_snooping(me)))
      write("你停止監聽"+ob->query("name")+"所收到的訊息。\n");
    snoop(me);
    return 1;
  }
  ob = find_player(arg);
  if (!ob) ob = find_object(arg);
  if(!ob || (!ob->visible(ob) && (wizhood(ob) == "(admin)" || wizhood(ob)
    == "(manager)"))) return notify_fail("沒有這個人。\n");
  if( me==ob ) return notify_fail("請用 snoop none 解除監聽。\n");
  snoop(me, ob);
  return 1;
}

int do_fire(string arg)
{
  object me,obj,link;
  if (!arg) return 1;
  me = this_player();
  obj = find_object(arg);
  if (!obj) obj = present(arg, me);
  if (!obj) obj = present(arg, environment(me));
  if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) );
  if (!obj) return notify_fail("沒有這樣物件....。\n");
  if (userp(obj)) 
  {
    message_vision("$N招喚神龍﹐對著$n吐出龍珠。\n", me, obj);
    tell_object(obj,"一顆巨大的龍珠帶著火光向你飛來。\n");
    message_vision("龍珠正中$n巨大的火燄將$n瞬間化做飛灰。！\n",obj,obj);
//    log_file("quit",
//    sprintf("%s於 %s 離開遊戲。", obj->short(), ctime(time())));
//    CHANNEL_D->do_channel(me, "sys",
//                          sprintf("%s離開遊戲了。", obj->short()) );
//    obj->set("last_on", time());
//    obj->set("last_from", query_ip_name(obj));
    link=obj->query_temp("link_ob");
    link->save();
    destruct(link);
    obj->save();
    seteuid(ROOT_UID);
    destruct(obj);
  }
  else
  {
    message_vision("$N招喚神龍﹐對著$n吐出龍珠。\n", me, obj);
    message_vision("一瞬間龍珠將一切化為灰燼，一點兒灰也沒有剩下！\n",me);
    seteuid(geteuid(me));
    destruct(obj);
  }
  return 1;
} 


int do_summon(string str)
{
  object me,ob;
  if (!str) return 1;
  me = this_player();
  ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("咦... 有這個人嗎?\n");
  if (environment(ob))
    tell_room(environment(ob),"天空中伸出一隻龍爪將"+(string)ob->query("name")+"抓了起來, 然後不見了.\n", ob);
  tell_object(ob,"一隻龍爪把你抓了起來, 你眼前一陣黑....\n");
  ob->move(environment(me));
  tell_object(me, "你呼喚神龍把"+(string)ob->query("name")+"抓到你的面前.\n");
  tell_object(ob,".... 醒來時發現是"+(string)me->query("name")+"把你弄過來的.\n");
  tell_room(environment(ob),(string)ob->query("name")+"突然出現"+"在你眼前\n",({me,ob}));
  return 1;
}

int do_shutdown(string arg)
{
  int i;
  if(arg=="downcgy")
  {
    message( "system",HIY+"空中忽然出現一隻巨大的五爪金龍遮住了半個天空\n"+NOR , users() );
    message( "system",HIW+"五爪金龍對著地面吐出一顆巨大的龍珠\n"+NOR, users());
    call_out("do_shutdown",10,"start1");
  }  
  if(arg=="start1")
  {
    message("system",HIY+"\n龍珠帶著火光迅速的向地面落下！\n\n"+
                     HIM+"  你感到自己似乎快被烤焦了\n"+NOR , users() );
    call_out("do_shutdown",10,"start2");
  }
  if(arg=="start2")
  {
    message( "system", HIW+"             轟的一聲巨響!!!!!!!!\n\n"+
             RED+"                 龍珠落到地面，霎時化做一團火球…\n\n"+
             HIR+"火球瞬間變大，霎時吞沒整個大地，你看到大片火焰向你襲來，眼前一片血紅\n\n"+
             NOR+RED+"              所有的一切都在瞬間陷入火海....\n\n"+
             NOR+"            然後你的眼前是一片黑暗....無止盡的黑暗....\n\n", users() );
    message( "system", "遊戲重新啟動﹐請稍候一分鐘再 login 。\n", users() );
    shutdown(0);
  }
  return 1;
}

int query_autoload()
{
  if(!this_player()) return 0;
  if (wizardp(this_player()))
    return 1;
  else return 0;
}

