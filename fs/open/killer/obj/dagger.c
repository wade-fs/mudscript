#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC "滅神匕首" NOR,({"god dagger"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是葉秀殺與莊靜柔與柴榮三人之間的信物，\n
當年的事件之後，這把匕首就不知去向，如今居然出現在你的手上。\n
可以利用它轉換本身的靈力，變成強大的傷害力，使對手受到傷害(hurt)。\n");
                set("value",1000);
                set("material", "steel");
        
                set("no_sell",1);
        }
        init_dagger(80);

// These properties are optional, if you don't set them, it will use the
// default values.

        set("wield_msg", "$N從懷中摸出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n藏入懷中。\n");

// The setup() is required.
        setup();
}

void init()
{
    if( this_player()==environment() )
    {
      add_action("do_hurt","hurt");
      add_action("do_auc","auc");
    }
}

int do_auc(string str)
{  
   if (str=="god dagger")
   {
     message_vision("$N覺得滅神匕首，已經沒用了，因此將匕首折斷了\n",this_player());
     destruct(this_player());
     this_player()->set("sellring",2);
     return 0;
   }    
}

int do_hurt(string arg)
{
   int buf,sk;
   object ob,me,target;
   string str;
   me = this_player();
   ob = this_object();
   sk=me->query_skill("dagger",1);
   if (!arg )
   return notify_fail("你想射空氣呀﹖\n");
   target = present(arg, environment(me)); 
   if(!target) return notify_fail("找不到這個人!!\n");
   if(!me->is_fighting(target) )
   return notify_fail("戰鬥中才能使用唷!!\n");
   if(this_player()->query("class") != "killer")
   return notify_fail("這是殺手專用的東西\n");
   if(this_player()->query_skill("dagger",1) < 50 )
   return notify_fail("小朋友，短兵刃練好一點，再用吧！\n");
   if( target->query("no_kill") ) 
   return notify_fail("這傢伙你不能動就是不能動。\n");
   if( !wizardp(me) && environment(me)->query("no_fight") )
       return notify_fail("這裡禁止戰鬥。\n");
   if( !target->is_character() || target->is_corpse() )
       return notify_fail("看清楚點,它並不是活物。\n");
   if(me->query("atman") < 50)
       return notify_fail("抱歉！靈力不夠啦！\n");
   if( target == me ) 
       return notify_fail("殺手目前還沒有，練屍魂人的打算啦！不要找死啦！\n");
   if(target->is_busy())
       return notify_fail("仁慈一點啦！他正被你的靈氣銀光制住，動彈不得\n");

  if ( me->is_fighting(target) || me->is_killing(target) )
  {
   tell_object(me,HIG"雙手握住匕首，將自身的靈力灌入匕首之中。\n"NOR);
   tell_object(me,HIG"只見匕首發出一道耀眼的光芒，一道銀光急射而出\n"NOR);
   if( random(sk) > random(target->query("dodge",1)) )
     {//dodge lv 100的話，因為對手dodge不定，以lv 100來算
        tell_object(me,HIM"對手一不留神，被銀光射中，受到嚴重傷害\n" NOR);
        target->add("kee",-random(sk));
        target->start_busy(1);
        me->add("atman",-50);
        return 1;
     }
   else
    {
        tell_object(me,HIM"$N發現了你的行動，輕易的閃過去\n" NOR,target);
        me->add("atman",-10);
        me->start_busy(1);
        return 1;
     }
  }
  return notify_fail("想利用bug呀！，戰鬥中才能用啦！\n");
}

int wield()
{
  if(!this_player()) return 1;
 if(this_player()->query("class") != "killer")
    return notify_fail("這是殺手專用的東西\n");
 if(this_player()->query_skill("dagger") < 50 )
     return notify_fail("小朋友，短兵刃練好一點，再用吧！\n");
 else 
 {
::wield();
  }
  return 1;
}
