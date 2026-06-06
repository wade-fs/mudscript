//judge.c
//增加玩家是否離線的判斷 by blazakira 2011/2/19
//排版 by blazakira 2011/10/12

#include <login.h>
#include <ansi.h>
inherit NPC;

int n = 0;

void create()
{
  set_name( "冰判官", ({ "judge ice","ice","judge" }) );
  set( "long",
    "這是一位審查玩家是否為笨蛋的審判官，你必須連續答對(answer)他三個問題才能\n"
    "脫離他的魔掌。\n\n");
  set("nickname", HIB"冷血無情"NOR);
  set("title","專門對付笨蛋的審判官");
  set("gender", "男性");
  set("attitude","heroism");
  set("no_lyssa",1);
  set("age",40);
  set("no_kill",1);
  set("no_fight",1);
  setup();
}

void init()
{
  object me;

  seteuid( geteuid (this_player()));
  me = this_player();
  me->set_temp( "old_startroom", me->query("startroom") );
  if( !wizardp(me) )
    me->set( "startroom", ROBOT_CHECK );
  if( !query_heart_beat(this_object()) ) set_heart_beat(1);
  add_action( "do_answer", "answer" );
  add_action( "babe_jail", "", 1) ;
  call_out( "judge", 1, me );
}

int babe_jail() // 新增強力判斷 action 防止玩家亂搞 by ACKY
{
  object ob = this_player();
  if( ((string)query_verb()=="recall") ||
    ((string)query_verb() =="perform") ||
    ((string)query_verb() =="practice") ||
    ((string)query_verb() =="exert") ||
    ((string)query_verb() =="cast") ||
    ((string)query_verb() =="conjure") ||
    ((string)query_verb() =="do") ||
    ((string)query_verb() =="c_in") ||
    ((string)query_verb() =="c_home") ) {
    write (HIY"冰判官說道：「在這兒除了回答問題，你還想幹嘛？」\n"NOR);
    return 1;
  }
  if( ((string)query_verb()=="ct") ||
    ((string)query_verb() =="tell") ||
    ((string)query_verb() =="gt") ||
    ((string)query_verb() =="reply") ||
    ((string)query_verb() =="shout") ||
    ((string)query_verb() =="war") ||
    ((string)query_verb() =="dead") ||
    ((string)query_verb() =="chat") ||
    ((string)query_verb() =="rumor") ||
    ((string)query_verb() =="music") ||
    ((string)query_verb() =="chat") ||
    ((string)query_verb() =="ht") ||
    ((string)query_verb() =="cb") ||
    ((string)query_verb() =="mud") ||
    ((string)query_verb() =="es") ) {
    write (HIY"冰判官說道：「想搬救兵？門兒都沒有！」\n"NOR);
    return 1;
  }
  return 0;
}

string color()
{
  if( ++n>7 )
    n=1;
  switch(n) {
    case 1: return HIR;
    case 2: return HIB;
    case 3: return HIY;
    case 4: return HIG;
    case 5: return HIY;
    case 6: return HIM;
    case 7: return HIW;
  }
}
// by ACKY
// 新的判定方式, 好算但盡量防止zmud
void judge( object me )
{
  int a, b, c, d, answer;
  string name, oper, tmp;

  if(!me || !environment(me)) return ;

  a = random(20) + 1;
  b = random(20) + 1;
  c = random(20) + 1;
  if( b > a ) {
    d = a;
    a = b;
    b = d;
  }
  name = me->query("name") + "(" + me->query("id") + "), ";

  switch(random(5)) {
    case 0:
      tmp = random(2) ? "加" : "加上";
      answer = a + b;
      oper = chinese_number(a) + tmp + chinese_number(b) + "等於多少？";
      break;
    case 1:
      tmp = random(2) ? "加" : "加上";
      answer = a + b + c;
      oper = chinese_number(a) + tmp + chinese_number(b) + "再加" + chinese_number(c) + "等於多少？";
      break;
    case 2:
      answer = a - b;
      tmp = random(2) ? "減去" : "減掉";
      oper = chinese_number(a) + tmp + chinese_number(b)+ "等於多少？";
      break;
    case 3:
      tmp = random(2) ? "乘以" : "乘上";
      if( a * b <= 100 ) {
        answer = a * b;
        oper = chinese_number(a) + tmp + chinese_number(b)+ "等於多少？";
      } else {
        answer = (a * b) % 10;
        oper = chinese_number(a) + tmp + chinese_number(b)+ "，個位數等於多少？";
      }
      break;
    case 4:
      answer = a % b;
      oper = chinese_number(a) + "除以" + chinese_number(b)+ "餘多少？";
      break;
  }
  if( random(2) )
    tell_room( environment(), HIY"冰判官問道：「" + color() + name + oper + HIY"」\n"NOR );
  else
    tell_object( me, HIY"冰判官問道：「" + color() + oper + HIY"」\n"NOR );
  call_out( "say_answer", 20+random(6), me );
  me->set_temp( "quiz/q", answer );
}

void say_answer( object me )
{
  string name, ans;

  if(!me) return ;
  ans = chinese_number( me->query_temp("quiz/q") );
  name = me->query("name") + "(" + me->query("id") + ")";

  if( !undefinedp(me->query_temp("quiz/q")) ) {
    tell_object( me, "冰判官說道：「" + name + "，這麼簡單都不會？答案等於" + ans + "。」\n" );
    if( !wizardp(me) ) {
      command( "say 「" + name + "，你反應太慢了喔！給我小心一點！」" );
      me->add_temp( "quiz/a", -1 );
      if( me->query_temp( "quiz/a" ) <= -5 ) {
        command( "say 「" + name + "，你再發呆啊！再遲鈍啊！先滾回去睡十分鐘吧！」\n" );
        me->do_command( "sleep 0 10 0 0" );
      }
    }
  }
  if(me && environment(me) == environment() )
    call_out( "judge", 1, me );
}

int do_answer( string arg )
{
  string s, name;
  object me;
  int ans;

  me = this_player();
  if( undefinedp(me->query_temp("quiz/q")) )
    return notify_fail( "必須等下一題。\n" );
  notify_fail( "請回答一組數字。\n" );
  if( !arg ) return 0;

  tell_object( me, CYN"你答道： " + arg + "\n"NOR );
  name = me->query("name") + "(" + me->query("id") + ")";
  if( sscanf( arg, "%d", ans )==1 ) {
    if( ans==me->query_temp("quiz/q") ) {
      me->add_temp( "quiz/a", 1 );
      me->delete_temp("quiz/q");
      command( "say " + name + "答對了！" );
      command( "pat " + me->query("id") );
      if( me->query_temp("quiz/a") >= 3 ) {
        command( "say 「很好，"+ name + "，你看起來不像笨蛋，你可以回家了。」\n" );
        me->delete_temp("quiz");
        me->set( "startroom", STARTROOM );
        me->move(STARTROOM);
      }
    }
    else {
      command( "say " + name + "答錯了！" );
      me->add_temp( "quiz/a", -1 );
      if( me->query_temp("quiz/a") <= -5 ) {
        command( "say 「" + name + "，你再給我亂猜啊！笨蛋！先滾回去睡十分鐘吧！」\n" );
        if( !wizardp(me) )
          me->do_command( "sleep 0 10 0 0" );
      }
    }
  }
  else
    return 0;
  return 1;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob )
  {
    ::die();
    return;
  }
  write( HIW"冰判官冷笑道：「連我你也敢殺。」\n"NOR );
  tell_object( users(), "【"HIC"閒聊"NOR"】"HIC"冰判官(judge)說道：心狠手辣的" + ob->query("name") + "竟敢將我殺害，快通知 wiz 幫我報仇！\n"NOR );
  ob->add("kill_judge",1);
  write_file("/log/kill_judge",sprintf("%s(%s) 殺死冰判官於 %s\n",ob->name(1),ob->query("id"),ctime(time())));
  ::die();
}
