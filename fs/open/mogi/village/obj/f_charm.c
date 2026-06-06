//封魔符...給玩家使用的道具....可以使對手busy...  made by eva
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("封魔符", ({"charm"}));
    set_weight(30);
        set("long","畫滿符咒的黃紙, 朝對象使用的話可以暫停對手的動作!
使用方法:freeze <對象>\n");
        set("unit","張");
        set("base_unit","張");
     set("value",500000);
        set_amount(1);
    setup();
}

void init()
{
    if (this_player()==environment())
        {
        add_action("do_freeze","freeze");
        }
}

int do_freeze(string arg)
{
    object me,target;
    me=this_player();
    if( !me->is_fighting() && !me->is_killing() )
        return notify_fail("現在不是戰鬥中, 你不能使用封魔符!\n");
    if (!arg)
        return notify_fail("你想要封住誰呀?\n");
    target=present(arg,environment(me));
    if (!target->is_character() || target->is_corpse())
        return notify_fail("對非生物使用封魔符是沒有用的!!\n");
    if(target->is_busy())
         return notify_fail("敵人的行動被封住了不用在用封魔符了!!\n");
    if (me->query("sen") < (int) (me->query("max_sen") * 0.6) || me->query("sen") < 60)
        return notify_fail("你沒有足夠的精神去念咒!\n");
    if (me->is_fighting(target) || me->is_killing(target))
        {
        message_vision(HIW"$N口中念道: 天 地 之 靈 聽 我 之 命～\n"NOR,me,target);
        me->start_busy(1);
        message_vision(HIY"$N丟出一張符咒, 大喝：～～～封～～～\n"NOR,me,target);
     if(arg=="fire king" || arg=="king"){
        me->add("sen",-40);
        add_amount(-1);
      write(HIC"結果封印剛飛到一半，就被焚天魔王的"HIR"極火真氣"HIC"焚毀!!\n"NOR);
        return 1;
                                        }
     else if(random(100)>50) {
      me->add("sen",-40);
      message_vision(HIY"$n瞬時發出強大的內力使$N的封魔符法力,無法發揮!!\n"NOR,me,target);
      add_amount(-1);
      return 1;
      }
     else {                                   
       target->start_busy(3);
    me->add("sen",-40);
        message_vision(HIC"$n受到$N封魔符的封印, 變得無法動彈!!\n"NOR,me,target);
        add_amount(-1);
        return 1;
          }
        }
    else
        {
        return notify_fail("你又沒有在攻擊他, 封住他幹嘛?\n");
        }
}
