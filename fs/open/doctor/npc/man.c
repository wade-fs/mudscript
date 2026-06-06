//因為是玩家 所以會有很多變數 因此額外增加判斷是否存在著老婦人 by blazakira 2011/3/22
//分段獎勵 獲得save_die指令使用許可後 如果有回來救人便可額外獲得原設計者的構思獎勵 by blazakira 2011/3/24

#include <ansi.h>
inherit NPC;

void create()
{
  set_name(RED"<垂死> "NOR"年輕男子", ({"young man","man"}));
  set("long", "一個年輕男子，病的好像死人一般。\n");
  setup();
}

void init()
{
  add_action("do_check","check");
  add_action("do_heal","cmd");
}

int do_check(string arg)
{
  object me=this_player();

  if(arg == "young man" || arg == "man")
  {
    if(!me->query("doctor/agree_woman")==1)
    {
      if(!present("old woman",environment(this_object()))) {
        write(HIY"年輕男子迴光返照似大吼﹕母…母親！\n"NOR,me);
        this_object()->die();
        return 1;
      }
      write(HIY"老婦人著急的大叫：你想幹什麼！！！\n"NOR,me);
      return 1;
    }
    else if(this_object()->query("save")==1) {    
      write(HIY"他已經被人拯救了！\n"NOR,me);
      return 1;
    }else{
      write(HIY"你搬了張椅子到了病床旁邊...\n"NOR,me);
      call_out("do_check1",3,me);
      return 1;
    }
  }
}

int do_check1(object me)
{
  write(HIY"你抓起了年輕男子的手腕，開始為他把脈...\n"NOR,me);
  call_out("do_check2",5,me);
}

int do_check2(object me)
{
  write(HIY"你感覺到他微弱不堪的脈搏，似乎還慢慢的在減弱當中...\n"NOR,me);
  call_out("do_check3",3,me);
}

int do_check3(object me)
{
  write(HIY"你皺了皺眉頭，發現情況似乎不太妙...\n"NOR,me);
  call_out("do_check4",3,me);
}

int do_check4(object me)
{
  if(!present("old woman",environment(this_object()))) {
    write(HIY"年輕男子迴光返照似大吼﹕母…母親！\n"NOR,me);
    this_object()->die();
    return 1;
  }
  write(HIY"你看著一旁焦急的老婦人，思考著不知道應不應該跟她說...\n"NOR,me);
  call_out("do_check5",5,me);
}

int do_check5(object me)
{
  write(HIY"你鼓起勇氣，終於決定還是要說出口了...\n"NOR,me);
  me->set("doctor/check_man", 1);
  me->delete("doctor/agree_woman");
  return 1;
}

int do_heal(string arg)
{
  object me=this_player();
  object ob=this_object();

  if( arg != "save_die man" && arg != "save_die young man" ) //return notify_fail("你想要救活誰???\n");
  {
    write ("你想要救活誰???\n");
    return 1;
  }
  if(!me->query("doctor/save_die"))
//    return notify_fail("你還沒學會那可救不了他的！\n");
  {
    write ("你還沒學會那可救不了他的！\n");
    return 1;
  }
  if(me->query("force") < 8000)
//    return notify_fail("以你現在的能力是救不了他的！\n");
  {
    write ("以你現在的能力是救不了他的！\n");
    return 1;
  }
  if(ob->query("save")==1)
//    return notify_fail("他看起來健健康康的，根本就沒必要救他的呀！\n");
  {
    write ("他看起來健健康康的，根本就沒必要救他的呀！\n");
    return 1;
  }
  if(!present("old woman",environment(this_object()))) {
    write(HIY"年輕男子迴光返照似大吼﹕母…母親！\n"NOR,me);
    this_object()->die();
    return 1;
  }
  if(me->query("doctor/save_die_gift")==1) {
    ob->set("name","年輕男子");
    ob->set("long","一個非常健康的年輕男子！");
    ob->set("save",1);
//    return notify_fail("他已經被你拯救了！\n");
    write ("他已經被你拯救了！\n");
    return 1;
  }
  message_vision("$N"HIY"施展出銀針門秘傳絕技「聖手回春術」，將手搭在"NOR"年輕男子"HIY"的頭頂與氣海，灌輸自己的\n"
    "真氣，想要把"NOR"年輕男子"HIY"從鬼門關救回來!!!\n"NOR,me,ob);
  message_vision(HIY"$N終於把"NOR"年輕男子"HIY"給救活了，不過也累出了滿身大汗!!\n"NOR,me,ob);
  message_vision(HIG"$N因此獲得了500點的經驗值！\n"NOR,me);
  write(HIY"一旁的老婦人見狀，趕緊奔了過來，激動的說道：這位神醫果然名不虛傳，多謝您救了小\n"+
    "犬一命，老身無以為報，只有這顆本來要給小犬的「天王保命丹」"HIY"又稱「"HIC"救命靈丹"HIY"」，那\n"
    "現在就把它獻給您了，實在萬分感謝！！\n\n"NOR);
  new("/obj/standby-pill")->move(me);
  me->add("combat_exp",500);
  me->set("doctor/save_die_gift",1); //領取另個額外獎勵的判斷
  ob->set("name","年輕男子");
  ob->set("long","一個非常健康的年輕男子！");
  ob->set("save",1);
  return 1;
}
