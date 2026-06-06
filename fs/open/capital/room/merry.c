// Room: /open/capital/room/merry
#include "/open/common/common.h"
#include <ansi.h>
#include <room.h>
#include <command.h>

inherit ROOM;

int in_merry;
object husband, wife;
string event;

object	po, horse, bedan, music, firework, misc,
	relative, friend, people;

void create ()
{
  set ("short", "民政司");
  set ("long", @LONG
這是皇上特地為百姓開闢的一官位，專門負責處理結婚事誼如果您
想結婚，請在這兒登記(log_marry),當然，記得把另一半也帶過來，另外準備
黃金十兩。一切結婚事項會有專人辦妥，並且附贈新房一間。對了, 皇
上體查民間疾苦, 近來怨偶甚多, 所以特地開辦離婚手續, 請要離婚的
(divorce) 請趕快, 否則沒機會了. 想到這, 不禁想起....
	         自古多怨偶, 從今少煩憂.
對了, 皇上還說, 要強迫離婚也可以, 帶一千兩黃金來吧.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"r72",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
           永浴愛河

           早生貴子

",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

  setup();
}

void init()
{
  add_action ("divorce", "divorce");
add_action ("log", "log_marry");
  add_action ("logout", "logout");
  add_action ("answer", "answer");
}

int divorce (string arg)
{
  string couple;
  object me, obj;

  me = this_player();
  if (couple = me->query("couples/id")) {
    if (!obj = present (couple, this_object())) {
      if (me->can_afford (10000000)) {
	obj = FINGER_D->acquire_login_ob (couple);
	if (obj) {
	  obj->delete ("couples");
	  obj->save();
	  destruct (obj);
	  me->pay_money (10000000);
	  me->delete ("couples");
	  write ("既然你身懷鉅款, 想離婚就讓你離婚吧.!\n");
	}
	else {
	  me->delete ("couples");
	  write ("噫? 你另一半不見了, 好吧, 就讓你如願.\n");
	}
      }
      else {
        write ("要離婚的話, 要找另一半過來.\n");
      }
    }
    else if (!obj->query_temp ("divorce")) {
      me->set_temp ("divorce", 1);
      write ("等你另一半也來註冊離婚, 這樣手續就完成了.\n");
    }
    else if (obj->query ("couples/id") == me->query ("id")) {
      obj->set_temp ("divorce", 0);
      me->delete ("couples");
      obj->delete ("couples");
      message_vision("民政司長說: 恭喜, 你們兩人從今以後就自由了.\n", this_player());
    }
    me->save();
  }
  else {
    write ("沒結婚就想離婚?\n");
  }
  return 1;
}

void logout()
{
  in_merry = 0;
  event = "";
  remove_call_out("wife");
  remove_call_out("husband");
  remove_call_out("confirm_wife");
  remove_call_out("confirm_husband");
  tell_room(this_object(), "民政司長說道: 本次結婚申請因故取消。\n");
}

int log()
{
  object	me;
  string	name;
  int		age;

  me=this_player();
  if (me->query("couples")) {
    if (!present("wedding ring", me)) {
	write ("民政司長說: 我看看....\n民政司長說: 你只是戒指掉了, 我馬上補給你.\n");
	if (new(RING)->move(me))
	  write ("民政司長說: 戒指給你, 可別再搞丟了喔.\n");
	else
	  write ("民政司長說: 對不起, 目前戒指缺貨, 找大神看看有沒有.\n");
    }
    else
      write ("民政司長說: 噫? 你想再婚? 門兒也沒有.\n");
    return 1;
  }
  
  if (in_merry)
    return notify_fail ("民政司長說: 現在已經有人登記要結婚，你等等再來。\n");

  name = me->name();
  age = me->query("age");
  if ( age < 16) {
    event = "";
    message_vision("民政司長說: "+me->name()+"啊，太早結婚會操死喔，長大點再來吧。\n",
	me);
    return 1;
  }
  if ( !me->pay_money(100000) ) {
    event = "";
    message_vision("民政司長說: "+me->name()+"啊，想結婚總要有些本兒吧，先去賺錢再來。\n",
	me);
    return 1;
  }
  message_vision("民政司長說道: "+name+"啊，看在錢的份上，就幫你辦結婚事誼吧。\n"+
		 "民政司長說道: "+name+"，開始回答我一些問題，"+
		 "每個問題給你一分鐘考慮。\n民政司長翻了翻簿子，想了一下...\n",me);
  
  in_merry = 1;
  if (me->query("gender") == "男性") {
	wife = 0;
	husband = me;
	me->set_temp("in_merry",1);
	call_out("wife", 3);
  }
  else {
	me->set_temp("in_merry",1);
	husband = 0;
	wife = me;
	call_out("husband", 3);
  }
  return 1;
}

void wife ()
{
  message_vision("民政司長說道: "+husband->name()+"，請回答我你的老婆是誰!\n",
	husband);
  event = "ask_wife";
  call_out("logout", 60);
}

void confirm_husband()
{
  message_vision(
    "民政司長說道: "+husband->name()+"，你願意一生保護"+wife->name()+"?\n"+
    "並且愛他照顧他信任他體貼他嗎(y/n) ?\n", husband);
  event = "confirm_husband";
  call_out("logout", 60);
}

void confirm_wife()
{
  message_vision(
    "民政司長說道: "+wife->name()+"，你願意一生跟隨"+husband->name()+"?\n"+
    "並且愛他照顧他信任他體貼他嗎(y/n) ?\n", wife);
  event = "confirm_wife";
  call_out("logout", 60);
}
  
int answer(string arg)
{
  object	me=this_player();

  if (me != husband && me != wife) return
    notify_fail ("民政司長說道: 你又不是新郎新娘，你花轟啊。\n");

  if (!arg) return 0;

  if (!in_merry) return notify_fail ("民政司長說道: 想結婚就先登記吧。\n");
  switch (event) {
	case "ask_husband":
	  event = 0;
	  if (me != wife) return
		notify_fail ("民政司長說道: 別急，還沒輪到妳。\n");
	  remove_call_out("logout");
	  if (!husband = present(arg, environment(me))) {
		message_vision("民政司長說道: "+me->name()+
		  "你的對象不在啊，先找他來吧，等妳一分鐘喔。\n", wife);
		call_out("wife", 60);
	  }
	  else {
	    if ( husband->query("gender")=="女性") {
	      message_vision("民政司長說道: 對不起，請找個有茶嘴的當老公。\n",
		wife);
	    }
	    else {
	      call_out("confirm_wife",3);
	      message_vision("$N回答說: 我要嫁$n為妻!\n", me, husband);
	    }
	  }
	  break;
	case "ask_wife":
	  if (me != husband) return
		notify_fail ("民政司長說道: 別急，還沒輪到你。\n");
	  event = 0;
	  remove_call_out("logout");
	  if (!wife = present(arg, environment(me))) {
		message_vision("民政司長說道: "+me->name()+
		    "你的對象不在啊，先找她來吧，等你一分鐘喔。\n", me);
		call_out("wife", 60);
	  }
	  else {
	    if ( wife->query("gender")=="男性") {
 	      message_vision("民政司長說道: 對不起，請找個會生小孩的當老婆。\n",me);
	    }
	    else {
	      call_out("confirm_wife",3);
	      message_vision("$N回答說: 我要娶$n為妻!\n", me, wife);
	    }
	  }
	  break;
	case "confirm_husband":
	  if (me != husband) return
		notify_fail ("民政司長說道: 別急，還沒輪到你。\n");
	  event = 0;
	  remove_call_out("logout");
	  if (arg == "y" || arg == "yes" || arg == "Y" || arg == "Yes") {
	    message_vision("$N回答說: 是的。\n", me);
	    message_vision("民政司長說道: hmm...接下來就等人送紅包吧。\n",me);
//我把 void stop_merry()後面那段在這也加上去,結果竟可行...就醬子

	    husband->set("couples/id", wife->query("id"));
	    husband->set("couples/name", wife->name());
	    wife->set("couples/id", husband->query("id"));
	    wife->set("couples/name", husband->name());
	    husband->save();
	    wife->save();
	    
	    call_out("start_merry",3);
	  }
	  else {
	    message_vision("$N回答說: 喔! Kill me!!!\n", me);
	    message_vision("民政司長說道: 既然男方不答應，本次申請作廢。\n", me);
	    call_out("logout",1);
	  }
	  break;
	case "confirm_wife":
	  if (me != wife) return
		notify_fail ("民政司長說道: 別急，還沒輪到你。\n");
	  event = 0;
	  remove_call_out("logout");
	  if (arg == "y" || arg == "yes" || arg == "Y" || arg == "Yes") {
	    message_vision("$N回答說: 是的。\n", me);
	    call_out("confirm_husband",3);
	  }
	  else {
	    message_vision("$N回答說: 喔! Kill me!!!\n", me);
	    message_vision("民政司長說道: 既然女方不答應，本次申請作廢。\n", me);
	    call_out("logout",1);
	  }
	  break;
	default:
	  return 0;
  }
  return 1;
}

int wear_all()
{
  object	ob;

(ob=new("/autoload/ring.c"))->move(husband); ob->wear();
  (ob=new(MBOOTS))->move(husband); ob->wear();
  (ob=new(GLOVES))->move(husband); ob->wear();
  (ob=new(CLOTH))->move(husband); ob->wear();
  (ob=new(PANTS"))->move(husband); ob->wear();
  (ob=new(SCARF))->move(husband); ob->wear();
  new(FLOWER)->move(wife);
(ob=new("/autoload/ring.c"))->move(wife); ob->wear();
  (ob=new(GLOVES))->move(wife); ob->wear();
  (ob=new(LACE))->move(wife); ob->wear();
  (ob=new(GBOOTS))->move(wife); ob->wear();
  (ob=new(SKIRT))->move(wife); ob->wear();
  (ob=new(SUIT))->move(wife); ob->wear();
  (ob=new(CAPE))->move(wife); ob->wear();
  return 1;
}

void start_merry()
{
  object	wade;
  string	husband_name, wife_name;

  husband_name=husband->query("name");
  wife_name=wife->query("name");

  call_out("wear_all",1);

  remove_call_out("start_merry");
  CHANNEL_D->do_channel(this_object(), "mud",
	HIY + "新郎"+husband_name+"和新娘"+wife_name+"的結婚儀式開始........\n"+
	"各路親朋好友請來民政司送禮見證..........\n" + NOR);

  call_out("step1", 60);
}

void step1()
{
  CHANNEL_D->do_channel(this_object(), "mud",
	HIY + "繞京城一周....樂隊、炮隊、雜耍團等都請就位....\n"
	"新郎請上俊馬，新娘請上花轎。\n" + NOR);
  tell_room (this_object(), "你看到新郎上了俊馬新娘上了花轎。\n", 
	husband, wife);
  tell_object(husband, "你高高興興的上了俊馬。\n");
  tell_object(wife, "妳高高興興的上了花轎。\n");

  po		= new(PO);		po->move(MSTART_ROOM);
  horse		= new(HORSE);		horse->move(MSTART_ROOM);
					horse->start_merry(husband);
  bedan		= new(BEDAN);		bedan->move(MSTART_ROOM);
					bedan->start_merry(wife);
  music		= new(MUSIC);		music->move(MSTART_ROOM);
					music->start_merry();
  firework	= new(FIREWORK);	firework->move(MSTART_ROOM);
					firework->start_merry();
  misc		= new(MISC);		misc->move(MSTART_ROOM);
					misc->start_merry();
  relative	= new(RELATIVE);	relative->move(MSTART_ROOM);
					relative->start_merry(husband, wife);
  friend	= new(FRIEND);		friend->move(MSTART_ROOM);
					friend->start_merry(husband, wife);
  people	= new(PEOPLE);		people->move(MSTART_ROOM);
					husband->move(horse);
  					wife->move(bedan);

  call_out ("forward", 5+random(10), "north", 8);
}


void forward(string go_way, int times)
{
  object	env=environment(horse);
  int		dir;

  if (times == 0)
    if (go_way == "north") {
	times = 8;
	go_way = "south";
    }
    else {
	CHANNEL_D->do_channel(this_object(), "mud",
	  HIY + "禮成....新郎新娘送入洞房，其他人作鳥獸散。\n" + NOR);
	call_out ("stop_merry", 1);
    }

  tell_room (env, "整隊隊伍往前進...\n", husband, wife);
  tell_object(husband, "俊馬稍微震動了一下，隨著隊伍往前進....\n");
  tell_object(wife, "轎子稍微震動了一下，隨著隊伍往前進....\n");

	GO_CMD->main(po, 	go_way);
	GO_CMD->main(horse,	go_way);
	GO_CMD->main(bedan,	go_way);
	GO_CMD->main(music,	go_way);
	GO_CMD->main(firework,	go_way);
	GO_CMD->main(misc,	go_way);
	GO_CMD->main(relative,	go_way);
	GO_CMD->main(friend,	go_way);
	GO_CMD->main(people,	go_way);
	GO_CMD->main(husband,	go_way);
	GO_CMD->main(wife,	go_way);
	call_out("forward",5+random(5), go_way, times-1);
}

void stop_merry()
{
	husband->move("/player/inn");
	wife->move("/player/inn");
	destruct(po);
	destruct(horse);
	destruct(bedan);
	destruct(music);
	destruct(firework);
	destruct(misc);
	destruct(relative);
	destruct(friend);
	destruct(people);
	husband->set("couples/id", wife->query("id"));
	husband->set("couples/name", wife->name());
	wife->set("couples/id", husband->query("id"));
	wife->set("couples/name", husband->name());
	husband->save();
	wife->save();
	// 請吃喜酒
	// .....
}
