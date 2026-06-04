inherit SSERVER;
#include <ansi.h>

int sp_perform(object me);

int perform(object me, object target)
{
        string msg;
        object ob; 
        if(me->is_fighting()) 
        {
        target = offensive_target(me);
        } 
        else 
        {
        if(!target) return notify_fail("你要打誰？\n"); 
        }
        if(me->query("family/family_name")!="冥蠱魔教")
        return notify_fail("你不是魔教徒。\n");
        if(!ob = present("faint poison",me))
                return notify_fail("你的身上沒有一刻香。\n");
        if( environment(me)->query("no_fight") )
                return notify_fail("這裡不准戰鬥。\n");
        if( target->query("no_kill") )
                return notify_fail("這個傢伙你不能動就是不能動。\n");
       if(me->query("marks/evil-poison")==1 && me->query_skill_mapped("poison") == "coldpoison")
                return sp_perform(me);
        if(target->is_busy())
                return notify_fail("敵人 BUSY 中，快攻擊吧\n");

        msg=HIY + "$N從口中放出迷煙﹐往$n吹去﹗\n" + NOR;
        if(80>random(100)) 
          {
            msg+= GRN + "$n一不留神﹐吸到迷煙，行動變緩了。\n" + NOR;
            target->start_busy(3);
          } 
          else 
          {
             msg+=HIG + "$n識破了$N的毒招﹐身子一側﹐避了開去。\n" + NOR;
          }
         message_vision(msg, me, target);
         me->kill_ob(target);
         target->kill_ob(me);
         ob->add_amount(-1);
         return 1;
}
 

//新增解道evil-poison faint可以對敵全體
//明明就是香, 怎麼會只對一個人有用?_?
int sp_perform(object me)
{
    int i,flag,j;
    object *enemy;
    object ob; 
    enemy=me->query_enemy();
    j = sizeof(enemy);
    if(sizeof(enemy) < 1)
      return notify_fail("可能是精神錯亂的關系,你竟然找不到敵人!!\n");
    if(!ob = present("faint poison",me))
      return notify_fail("你的身上沒有一刻香。\n");
    if(sizeof(enemy) > 5) j=5;

    flag=0;
    for(i=0;i < j;i++)
    {
      if(!enemy[i]) continue;
      if(environment(me) != environment(enemy[i])) continue;
      flag++;
      if(enemy[i]->is_busy()) //npc busy跳過
      {message_vision("$n已在迷炫中, 迷魂香暫時對$n無效...\n",me,enemy[i]);}
      else
      {
      message_vision("\n" + HIW + "$N" + HIG + "的迷魂香在" + HIC + "「萬蠱蠶心術」" + HIG + "下啟動，$n" + HIY + "招架不及。\n" + NOR,me,enemy[i]);
      if(80>random(100))
      {
        message_vision(RED + "$N將$n給迷炫在迷魂鄉中!!!\n" + NOR,me,enemy[i]);
        enemy[i]->start_busy(3);
      }
      else
      {
        message_vision("可惜迷魂煙飄散, 對$n沒有任何影響..\n",me,enemy[i]);
      }
    }
    }
    if(!flag)
      return notify_fail("可能是精神錯亂的關系,你竟然找不到敵人!!\n");
    else
    {
      me->add("force",-(30*flag));
    }
    ob->add_amount(-1);
    return 1;
}

