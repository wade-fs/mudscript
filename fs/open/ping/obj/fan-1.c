// made by ccat
// 二版,改正以往須call 一個隱形怪獸的缺點,使用的變數也大為簡化.

#include <ansi.h>
#include <weapon.h>
inherit STABBER;
object user;
int sp,pp;
void create()
{
     set_name( "邪雲神扇",({"evil_fan"}) );
     set_weight(20000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","產於南蠻的鐵扇,受過邪神的祝福,會於戰鬥中招來閃電.\n");
            set("unit", "件");             
            set("value",2000);
            set("material","steal");
           }         
        init_stabber(15);
        setup();
}
void init()
{
     add_action("do_drop","drop"); 
     add_action("do_auc","auc"); 
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{ 
     int my_int,my_per,my_literate;
     ::wield();
     if( query("equipped") ) 
     {
        user = this_player();     // 取得使用者
        my_int = user->query_int(1);
        my_per = user->query_per(1);
        my_literate = user->query_skill("literate",1);
        if(my_literate > 60)
        my_literate = 60;
        sp = my_per*2 + my_literate;  // 特攻率
        pp = my_literate + my_int*2 ;  // 強度
        message_vision("邪雲神扇感受到$N的智慧,泛起一道藍光.\n",user);
        set_heart_beat(1);
     } 
}
int do_drop(string str)
{  
   if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N卸下了邪雲神扇,邪雲神扇變回一把普通的扇子.\n",user);
        set_heart_beat(0);
     }    
}    
 int do_give(string str)
{  
  if(str=="ruby_ring" || str=="all") 
     if( query("equipped") )
     { 
        message_vision("$N卸下了邪雲神扇,邪雲神扇變回一把普通的扇子.\n",user); 
        set_heart_beat(0);
     }
}
int do_unwield(string str)
{
   if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     {
        message_vision("$N卸下了邪雲神扇,邪雲神扇變回一把普通的扇子.\n",user);
        set_heart_beat(0);
     }   
}                       
int do_auc(string str)
{
  if(str=="ruby_ring" || str=="all")
     if( query("equipped") )
     { 
        message_vision("$N卸下了邪雲神扇,邪雲神扇變回一把普通的扇子.\n",user);
        set_heart_beat(0);
     } 
}     
void heart_beat()
{
  object *enemy,who;
  int i;

  if(!user)
    if(living(environment()))
      user=environment();
 if ( !objectp(user) )
	{
	set_heart_beat(0);
	return;
	} 
  if(environment() != user) return ;
 if( user->is_fighting() && query("equipped") )
  {
    if( sp > random(260) )
    {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
     if(!user || !enemy[i]) return ;
     if( environment(user) == environment(enemy[i]) )
      if( random(300) > enemy[i]->query_skill("dodge") )
     {
      message_vision(HIB+"邪雲神扇化做一道閃電,射向$N的心臟!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",pp,user);
      COMBAT_D->report_status(enemy[i], 0);
     }else
      message_vision(HIB+"邪雲神扇化做一道閃電,射向$N的心臟!...但是沒中...\n"
                     +NOR,enemy[i]);         
     }
  }
  return;
}  

