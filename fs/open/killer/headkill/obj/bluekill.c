#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name(HIB + "藍鳳絕殺令" + NOR, ({"bluekill card","card"}) );
	set("long",
"這就是傳說中的藍鳳絕殺令，經歷了千辛萬苦後，終於拿到手了。\n"+
"藍鳳組並不會任意出動，只有殺手全力追殺的人頭才會出動，因此可以利用它來追殺。\n"+
"使用法：bluekill xxxxx    xxxx是指該玩家的ID，且必須為殺手全力追殺的人頭\n"+
"只有一次的機會，必須在該角色死亡後立刻去拿人頭，交給葉秀殺\n");

	seteuid(getuid());
	set("unit","張");
        set("base_unit", "張");
	set("no_sell",1);
	set("no_give",1);
	set("no_drop",1);
	set("no_auc",1);
	set("value",0);
	set("weight",500);
	set_amount(1);
        setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("blue_kill", "bluekill");
  }
}

int blue_kill(string arg)
{      

   object ob,me=this_player();
   string obn;
   object ob1,ob2,ob3,ob4;

   ob1=new("/open/killer/headkill/npc/blunpc1");
   ob2=new("/open/killer/headkill/npc/blunpc2");
   ob3=new("/open/killer/headkill/npc/blunpc3");
   ob4=new("/open/killer/headkill/npc/blunpc4");


   if( !arg )                      return 0;
//   if( !ob = present(arg,me) )     return 0;
//   if( ob != this_object() )       return 0;
   if (me->query_temp("head") != 9)
        return notify_fail("你怎麼拿到這一支令牌的？\n");
   if(me->query("combat_exp") < 650000)
        return notify_fail("你這種戰鬥經驗這麼少的小鬼頭，也想要藍鳳組出動？\n");
    ob=find_player(arg);
    if(!ob) ob=find_living(arg);
    if (!ob) ob=LOGIN_D->find_body(arg);
    if(!ob)
      return notify_fail("你想追殺的人不在線上哦???\n");
    if(ob==me)
      return notify_fail("你想追殺自己呀!!!有沒有搞錯呀???\n");
     if(ob->query("title") != HIR + "殺手全力追殺的人頭" + NOR)
      return notify_fail("這種小角色，藍鳳組不會出動啦！\n");

    if (!me->query("use_blue") )
        me->set("use_blue",1);
    else
        me->add("use_blue",1);
    obn=ob->query("name");
    //防止使用瞬間移動
    ob->set_temp("no_transmit",1);  
    message_vision(HIM + "$N使用藍鳳絕殺令,要派藍鳳組追殺$n\n",me,ob);
    //證明這個玩家使用過藍鳳絕殺令
    me->set_temp("head",10);
    message("system",HIW + "藍鳳組組長喬小雨千里傳音：『\n
                藍鳳組聽令，藍鳳絕殺令已現，全力追殺" +ob->name()+"，至死方休!!』\n\n " + NOR,users());
    if (me->query("use_blue") > 4)
    {
            message("system",HIW + "藍鳳組組長喬小雨千里傳音：『\n藍鳳組聽令" 
        +me->name()+"第"+me->query("use_blue")+"次請我們出動』\n\n " + NOR,users());
    }   
     ob4->move(environment(ob));
     ob3->move(environment(ob));
     ob2->move(environment(ob));
     ob1->move(environment(ob));
     message_vision(
             HIM + "突然之間四道人影從四方閃出藍鳳組的殺手出現這裡。\n" + NOR,ob);
     message_vision(
             HIM + "藍鳳殺手喝道﹕"+ob->name()+" 你的死期到了!!\n" + NOR,ob,ob);

     ob4->kill_ob(ob);
     ob3->kill_ob(ob);
     ob2->kill_ob(ob);
    // ob1->kill_ob(ob);  因為此人是用背刺
     ob4->set_leader(ob);
     ob3->set_leader(ob);
     ob2->set_leader(ob);
     ob1->set_leader(ob);
     add_amount(-1);
     return 1;
}


