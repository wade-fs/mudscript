//修正錯字 by blazakira 2011/7/28

inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIM + "ξξ"NOR+HIW"．" + HIG + "五" + HIW + "‧" + HIC + "色"HIW+BLINK"˙"NOR+HBRED+HIY"封"NOR+HIW+BLINK"˙"NOR+HIC"靈" + HIW + "‧" + HIG + "臺" + HIW + "．" + HIM + "ξξ" + NOR,({"five color","five","color"}));
  set("long","一座破舊的祭臺，上面有一些大小不同的凹糟，似乎可以插入不\n"
    +"同的東西，你可以試著將符合凹槽的東西插(insert)進去，也許\\n"
    +"會有意想不到的結果出現!!\n");
  set("unit","座");
  set("value",100);
  set("no_get",1);
  set("no_sac",1);
  set("no_auc",1);
  set_weight(500000);
  setup();
}

void init()
{
  add_action("do_insert","insert");
}

int do_insert(string str)
{
  object ob=this_object(),me=this_player();

  if( !str )
    return 0;

  switch(str)
  {
    case "golden blade":
      if( !present(str,me) ) return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

      if(!ob->query("golden")==1 && (present(str,me)->query("magic-manor-obj")==1) )
      {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了五色封靈臺" + NOR + "$n" + HIC + "正確的位置上!!\n" + NOR,me,present(str,me));
        ob->set("golden",1);
        destruct(present(str,me));
        call_out("check",1,ob);
      }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
      }
      break;

    case "wood sword":
      if( !present(str,me) ) return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

      if(!ob->query("wood")==1 && (present(str,me)->query("magic-manor-obj")==1) )
      {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了五色封靈臺" + NOR + "$n" + HIC + "正確的位置上!!\n" + NOR,me,present(str,me));
        ob->set("wood",1);
        destruct(present(str,me));
        call_out("check",1,ob);
      }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
      }
      break;

    case "water ribbon":
      if( !present(str,me) ) return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

      if(!ob->query("water")==1 && (present(str,me)->query("magic-manor-obj")==1) )
      {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了五色封靈臺" + NOR + "$n" + HIC + "正確的位置上!!\n" + NOR,me,present(str,me));
        ob->set("water",1);
        destruct(present(str,me));
        call_out("check",1,ob);
      }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
      }
      break;

    case "fire fan":
      if( !present(str,me) ) return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

      if(!ob->query("fire")==1 && (present(str,me)->query("magic-manor-obj")==1) )
      {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了五色封靈臺" + NOR + "$n" + HIC + "正確的位置上!!\n" + NOR,me,present(str,me));
        ob->set("fire",1);
        destruct(present(str,me));
        call_out("check",1,ob);
      }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
      }
      break;

    case "soil claw":
      if( !present(str,me) ) return notify_fail("你在身上翻來翻去，卻怎樣也找不出這樣東西!!\n");

      if(!ob->query("soil")==1 && (present(str,me)->query("magic-manor-obj")==1) )
      {
        message_vision(HIC + "$N將" + NOR + "$n" + HIC + "鑲入了五色封靈臺" + NOR + "$n" + HIC + "正確的位置上!!\n" + NOR,me,present(str,me));
        ob->set("soil",1);
        destruct(present(str,me));
        call_out("check",1,ob);
      }else{
        message_vision("$N已經放在正確的地方囉!!\n",present(str,me));
      }
      break;

    default:
      message_vision("$N似乎想放什麼東西，但卻找不到正確的位置放!!\n",me);
          break;
  }
  return 1;

}

int check(object ob)
{
  ob=this_object();
  ob->add("check",1);

  if( ob->query("check") == 5 )
  {
    tell_object(users(),HIB + "\n\n\t聚靈山莊的封靈祭臺忽然劇烈的震動了起來!!\n" + NOR);
    tell_object(users(),HIB + "\n\t連在遠處的人們都能夠感受到這股大地的震動!!\n\n" + NOR);
    call_out("msg1",8,ob);
  }
  return 1;
}

int msg1(object ob)
{
  ob=this_object();
  tell_object(users(),HIC + "\n\n\t封靈祭臺在吸滿五色靈器的靈力之後，釋放出強大的光芒散射四方!!\n" + NOR);
  tell_object(users(),HIC + "\n\t光芒散射整個大地，大地因為光芒的照耀而顯得生機盎然!!\n\n" + NOR);
  call_out("msg2",8,ob);
  return 1;
}

int msg2(object ob)
{
  object room = environment(ob);
  ob=this_object();
  room->start();
  tell_object(users(),HIR + "\n\n\t光芒漸漸散去之後，大地也漸漸恢復了平靜，不再劇烈的震動!!\n" + NOR,ob);
  message_vision(HIW + "\n\t只見在原來的$N" + HIW + "開始慢慢的崩解，卻多了一條神秘的通道!!\n\n" + NOR,ob);
  room->add("exits/takeroad","/open/magic-manor/ghost/rest01");
  room->set("no_reset",1);
  room->start();
  call_out("close",60,ob);
  return 1;
}

int close(object ob)
{
  object me=this_player();
  object room = environment(ob);
  ob=this_object();
  message_vision(HIB + "「轟」隆一聲，$N" + HIB + "已完全的崩解，神秘入口也消失了!!\n" + NOR,ob);
  room->delete("exits/takeroad");
  destruct(ob);
  return 1;
}
