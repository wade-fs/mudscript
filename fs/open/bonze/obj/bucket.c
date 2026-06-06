// waterskin.c
//將水缸所在的該房間設定為禁止fill之類的說明就可以解釋為什麼不能fill了
//懶得去思考倒水進入水缸之後 還能fill的功能 因此直接在水缸上禁止就好 不過需注意 fill會先判斷房間 所以會忽略禁止的功能
//因此水缸所在房間必須沒有資源可以裝水 然後才是item物件上的指令判斷
//方法二的打死一位小和尚則是身邊有水缸作為紀錄 這樣一來就有三個水缸要裝水 且 每個和尚都可以打死一次 則為三個人能靠方法二解謎
//亦可參考火龍幻界的方式 在/open/fire-hole/fire2.c 用void init()來作為判斷 而 npc(dragon)死掉 則以npc身上的物件為媒介來紀錄在火龍王房間
//再者如果npc與該npc重生的房間為同一個 亦即不需要與其他房間呼應時 則可以直接在void reset() { 看房間裡的條件 如果合的話就 ::reset();}
//::reset();被包含在判斷句裡面 則符合後才會發動
//挑水次數暫定6次 接任務的npc均會移動 每小時解一次 在12小時內最大倒水次數為 6*12=72 次
//限定解謎總角色數量為 40位 =>40*72=2880 分為三個水缸 => 2880/3=960 取整數為每個水缸可裝900次的上限
//水缸滿了 理所當然得找下一個水缸
//三個都滿了 就需要等重開之後
//不過仍有一個方法可以擴充解謎人數
//即喝水(drink) 畢竟這是個使用指令 fill drink與獨創的解謎指令 倒水搭配的小quest
//因此喝水能減少水缸的水 貼近現實層面來說 是個相當正常的邏輯 所以我認為有效 故而允許玩家喝水來減少水缸的蓄水量

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
//int extra_func();
int do_fill();
int do_drink();

void create()
{
  set_name("水桶", ({ "bucket" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
  set("long", "一個用來裝水的木製桶子。\n");
  set("unit", "個");
  set("value", 2000);
  }
  set("液體", ([
      "種類": "水",
      "名稱": "清水",
      "剩": 0,
      "止渴" : 0,
//      "額外函數" : (: extra_func :) //於喝水時才會呼叫下方的參數 此呼叫方式內建在喝水的指令中(?
  ]) );
  setup();
}

void init()
{
  add_action("do_pour","pour");
  add_action("do_fill","fill");
  add_action("do_drink","drink");
  add_action("do_drink","drin");
  add_action("do_drink","dri");
  add_action("do_drink","dr");
  add_action("do_look","look");
  add_action("do_look","loo");
  add_action("do_look","l");
}

int do_pour(string arg) //需補充 在解quest的途中倒水才有效 解完之後的倒水行為不紀錄次數 每次重解quest時 將倒水次數歸零
{
  object ob = this_object() , me = this_player();
  object obj;

  if (!arg ) return 0; //沒有指定對象 則不做動作>>>arg不存在
  if ( !arg  || !obj = present(arg,environment(me))) //如果這房間沒有水缸的話
    return notify_fail("你想把水倒進哪裡？\n");
  else if ( query("液體/名稱") !="靈水" && query("液體/種類") !="靈泉" ) //邏輯上得裝清水才符合要求目前應該沒有其他液體是可以裝的
    return notify_fail("欸欸，等一下，你確定是從後山靈泉裡裝的水嗎？\n");
  else if ( arg !="vat" && arg !="water vat" ) //如果這房間沒有水缸的話
    return notify_fail("欸欸，等一下，少林寺的僧侶還在等水喝呢，快找少林寺的水缸吧。\n");
  else if ( query("fill") != 1 ) //如果倒過水的話
    return notify_fail("你發現水桶裡面沒有水。\n");
  else if ( obj->query("液體/剩") > 900 ) //為水缸次數的判斷
    return notify_fail(HIY"你發現水缸已經滿了。\n"NOR);
  set("液體/剩",0);
  set("液體/止渴",0);
  set("fill",0); //倒過水
  message_vision(CYN"$N提起$n將靈水倒進水缸裡。\n"NOR,me,ob);
  me->add_temp("quests/bonze/water/times",1); //在身上紀錄次數 是作為勤奮的判斷
  ob->add_temp("quests/bonze/water/times",1); //可作為隨機毀損=漏水的參數 預計作為水桶受損而無法裝水的可能性 使玩家再次領水桶而費時
  obj->add("液體/剩",1);
  obj->add_temp("quests/bonze/water/ppl/"+me->query("id"),1); //紀錄玩家id
  if ( me->query_temp("quests/bonze/water/times") > 6 && me->query_temp("quests/bonze/water/method2") == 2 ) { //為達成協助挑水任務的次數 且 需在挑水進行中才有效
    me->set_temp("quests/bonze/water/method2",3);
    return notify_fail("少林寺的僧侶告訴你﹕辛苦施主了，到這程度已是本寺最大的福報了，本寺二廚備有微薄謝禮。\n"); //找二廚回報 因為二廚是會走動的npc
  }
  return 1;
}
/*
int extra_func()
{
	if( !query("液體/剩") ) {
		write( "這壺茶已經被你喝光了, 你運勁於指, 將其震得粉碎。\n" );
		destruct( this_object() );
		return 1;
	}
	return 0;
}*/

int do_fill(string arg)
{
  if ( !arg ) return 0; //沒有指定對象 則繼續原動作指令
  if ( query("fill") == 2 ) //喝過水
  {
    set("液體/止渴",0);
  }
  if ( !query("液體/剩") && query("液體/止渴") > 0 && query("fill") == 1 ) { //第一次裝水後
    set("液體/剩",1);
  }
  set("fill",1); //已經裝水過時才設定為1次 只為了套用fill的動作 //只要裝水就是set=1 喝水 倒水都不等於1
  return 0;
}

int do_drink(string arg)
{//裝了水之後再look水桶 會導致可以喝水兩次的bug >>有點懶得繼續修正了XD
  if ( !arg ) return 0;
  if ( !query("液體/剩") && query("fill") == 1 ) { //已經裝水過時才設定為1次 只為了套用fill的動作
    set("液體/剩",1);
    add("fill",1); //喝過水
  }
  return 0; //此時有了剩餘次數 則在恢復喝水的動作時會扣1 並不會把止渴的參數歸零 所以會重複設定剩餘次數 因此補上額外的判斷(set("full"))
}

int do_look(string arg)
{
  if ( !arg ) return 0; //沒有指定對象 則繼續原動作指令
  if ( query("fill") == 2 ) //喝過水
  {
    set("液體/止渴",0); //為了再次裝水而設定
  }
  if ( !query("液體/剩") && query("液體/止渴") > 0 && query("fill") == 1 ) { //裝水後
    set("液體/剩",1);
  }
  return 0;
}
