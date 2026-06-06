// Room: /open/center/room/auroom.c
// copy from //u/c/chun/shop/auroom.c
// 增加 auc 時就自動先扣款。 by wade 11/19/1999

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit NPC;

object  auc_ob; // 拍賣的東西
string  ob_name;
string  name;   // 搶標的人
int     times;  // 第幾次拍賣
int     value;  // 搶標的價錢
int     had_auc;

void create()
{
        seteuid(geteuid());
        set_name("黑市老闆", ({ "auction boss", "boss" }) );
        set("long",@LONG
這是黑市老闆，專門喊標物價用的。
LONG );

        set("no_clean_up",1);
        set("channels", ({ "mud" }) );
        set("no_kill",1);
        times = 0;
        name = "";
        ob_name = "";
        setup();
}
void ident(object me)
{
  object *objs;

  objs = all_inventory(this_object()) ;
  if(!sizeof(objs)) {
    tell_object(me,"目前沒有任何拍賣物品。\n");
    return ;
  }
  tell_object(me,HIG + "黑市老闆交給你觀看了一下，鑑定結果如下：\n" + NOR);
  foreach(object obj in objs )
  {
    "/cmds/std/ident.c"->main(me,obj);
  }
}
void auction()
{
  object        *objs, me, auc_man=this_object(), who;
  int           half;

  remove_call_out("auction");
  who = find_player(name);
  if (times == 0) {
    ob_name = "";
    objs = all_inventory(this_object());
    if (half = sizeof(objs)) {
      auc_ob = objs[random(sizeof(objs))];
      ob_name = auc_ob->query("id");
      half = auc_ob->query("value")/2;
      if (!half) half = 1;
      value = random(4*half)+1;
      if( !auc_ob->query("base_unit") )
      {
        CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"
            "來來來！"+
            auc_ob->query_temp("auc_master")+
            "拍賣"+auc_ob->name()+HIG+"一"+auc_ob->query("unit")+"!!"+
            "起價"+CHINESE_D->cvalue(value)+HIG + "。"+NOR);
      }else{
        CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"
            "來來來！"+
            auc_ob->query_temp("auc_master")+
            "拍賣"+auc_ob->name()+HIG+chinese_number(auc_ob->query_amount())+auc_ob->query("base_unit")+"!!"+
            "起價"+CHINESE_D->cvalue(value)+HIG + "。"+NOR);
      }
      times = 1;
      name = "";
      had_auc = 0;
      call_out ("auction", 10);
    }
    return;
  }

  if (!auc_ob = present (ob_name, auc_man)) {
    ob_name = "";
    CHANNEL_D->do_channel(auc_man, "mud", "㊣黑市交易㊣"
        "拍賣品消失，取消本次拍賣。", users());
    if (arrayp(all_inventory(auc_man))) {
      times = 0;
      call_out ("auction", 10);
    }
    return;
  }

  me = find_player(auc_ob->query_temp("auc_master"));
  if ((name=="" && times > 3) || (name!="" && !who)) {  // 退貨
    ob_name = "";
    if (!me) {
      CHANNEL_D->do_channel(auc_man, "mud", "㊣黑市交易㊣"
        "物主不在，"+auc_ob->name()+"充公。", users());
      destruct(auc_ob);
    }
    else {
    if(me->is_ghost()) {
      CHANNEL_D->do_channel(auc_man, "mud", "㊣黑市交易㊣"
          "太可惜了，竟然沒人想要買"+auc_ob->name()+HIG + "。" + NOR);
      CHANNEL_D->do_channel(auc_man, "mud", "㊣黑市交易㊣"
          "黑市公司送貨員不能送"+auc_ob->name()+HIG + "到陰間只好充公。" + NOR);
      destruct(auc_ob); } else {
      auc_ob->move(me);
      CHANNEL_D->do_channel(auc_man, "mud", "㊣黑市交易㊣"
          "太可惜了，竟然沒人想要買"+auc_ob->name()+HIG + "。" + NOR);
      CHANNEL_D->do_channel(auc_man, "mud", "㊣黑市交易㊣"
          "黑市公司送貨員退還"+auc_ob->name()+HIG + "給原主"+me->name()+HIG + "。" + NOR);
    }
    }
    if (arrayp(all_inventory(auc_man))) {
      times = 0;
      call_out ("auction", 10);
    }
    return;
  }
  // 拍賣中…也許有人搶標，也許是拍板，進入下一次喊價
  if (times <= 3) {
    if (had_auc) {
      had_auc = 0;
      CHANNEL_D->do_channel(auc_man, "mud", "㊣黑市交易㊣"
        "嘿呦! 有人以"+CHINESE_D->cvalue(value)+HIG + "搶標! 歡迎加價!!" + NOR);
      times = 1;
    }
    else {
      CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"
        "第"+chinese_number(times)+"次拍賣"+auc_ob->name()+HIG + "! 叫價"+
        CHINESE_D->cvalue(value)+HIG + "! 請出價!" + NOR);
      times++;
    }
    call_out ("auction", 10);
    return;
  }
  // 三次喊價了，拍賣完成
  else {
    ob_name = "";
/* 因為已先付錢了，所以玩家不用再付錢一次，這個判斷拿掉
 * by wade@FS 11/19/1999
    if (who->pay_money(value))
*/
    {
      CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"+
        auc_ob->name()+HIG + "以"+CHINESE_D->cvalue(value)+HIG
        "拍賣給"+who->name()+HIG + "。" + NOR);
      if(who->is_ghost()) {
        CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"
          "喔喔, 你是鬼魂唷, 所買到的東西送不到陰間唷!");
        destruct(auc_ob);
        }
      if ( !auc_ob->move(who) ) {
        CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"
          "喔喔, 你負重囉，東西暫時放在地上了唷!");
	auc_ob->move(environment(who));
//        destruct(auc_ob);
        }
      if (me) {
        if (value > 20000) value /= 3;
        else if (value > 5000) value /= 2;
        me->pay_player(value);

        if(auc_ob)
        tell_object(me, HIG + "㊣黑市交易㊣"
            "你賣出"+chinese_number(auc_ob->query_amount())+auc_ob->query("unit")+auc_ob->name()+HIG + "，獲得"+
            CHINESE_D->cvalue(value)+HIG + "。\n" + NOR);
      }
      else
        CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"
          "賣了一把無主孤魂的東東, 賺死了。");
    }
/* 因為已先付錢了，所以這段根本沒有用
 * by wade@FS 11/19/1999
    else {
        CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"
          "哇勒, "+who->name()+"怎麼把錢花光了? 下次記得準備好錢喔!");
      if (me)
        auc_ob->move(me);
    }
*/
    if (arrayp(all_inventory(auc_man))) {
      times = 0;
      call_out("auction", 10);
    }
    return;
  }
  if (!all_inventory(auc_man)) {
    times = 0;
    call_out("auction",10);
  }
}

void do_buy (object me, int new_value)
{
  object        who;
  int           diff, exp;

  if (!auc_ob) {
    CHANNEL_D->do_channel(this_object(), "mud", "㊣黑市交易㊣"
      "哇! 東西消失了。無法拍賣啦!");
    return;
  }
  if (name == me->query("id")) {
    tell_object (me, "㊣黑市交易㊣"
      "想哄抬物價？少來了！\n");
    return;
  }
  if (new_value <= value) {
    tell_object (me, "㊣黑市交易㊣"
      "嘿嘿，想比黑市還黑? 乾脆自己開黑市好了。\n");
    return;
  }
  exp = (int)me->query("combat_exp");
    if( diff < 10000 )	{ diff = 10000; }else
    			{ diff = (int)(exp/10); }
/*
  if      (exp < 100)    { diff = value/1000; if (diff < 10)    diff = 10; }
  else if (exp < 1000)   { diff = value/100;  if (diff < 20)    diff = 20; }
  else if (exp < 10000)  { diff = value/10;   if (diff < 40)    diff = 40; }
  else if (exp < 100000) { diff = value/4;    if (diff < 100)   diff = 100; }
  else if (exp < 500000) { diff = value/2;    if (diff < 400)   diff = 400; }
  else                   { diff = value;      if (diff < 1000)  diff = 1000; }
*/
  if (new_value - value < diff) {
    tell_object (me, "㊣黑市交易㊣"
      "你出的價錢並不符合黑市運作規則，請提高至少"+
      CHINESE_D->cvalue(diff)+"。\n" + NOR);
    return;
  }
  // 做到搶標的人先付錢的話，第一步是：
  // 先還錢給上一次搶標的人(也許沒人搶過標)
  if (name) {   // 有人搶過標
    if (who = find_living (name)) {
      who->pay_player (value);  // 還給上次搶標的人錢
      tell_object (who, "㊣黑市交易㊣"
        "有人搶你的標，還給你上次出的錢："+
        CHINESE_D->cvalue (value)+"。\n");
    }
	}
    me->pay_money(new_value);  // 這次搶標的人要先付錢
  
  // 有人搶標，所以新價錢是第一次
  times = 1;
  // 把搶標的人記錄下來
  name=me->query("id");
  // 記錄新價錢
  value = new_value;
  had_auc = 1;
  call_out("auction", 1);
}

// me sell ob.
int do_sell(object me, object ob)
{
  if (ob_name != "") {
    tell_object(me, "㊣黑市交易㊣"" 開賣中\n");
    return 0;
  }

  if (!ob || !ob->move(this_object())) {
    tell_object(me, "㊣黑市交易㊣"
      "嘿嘿, 你想欺騙黑市公司的人員啊。\n");
    return 0;
  }
  ob->set_temp("auc_master", me->query("id"));
  times = 0;
  tell_object(me, "㊣黑市交易㊣"" 開賣啦\n");
  call_out ("auction", 1);
  return 1;
}
