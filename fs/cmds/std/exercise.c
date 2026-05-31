// exercise.c
// spi < skill數量時加的熟練值只有1
// 聖火的弟子superforce lv在100之前都沒有熟練值
//
// refix by chan

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int kee_cost, force_gain,spi,sk_mount,con;
        string ena_force;
        seteuid(getuid());
        if(me->query_condition("ff_poison"))
          return notify_fail("你氣血失調﹐無法運氣。\n");
        if(me->query_temp("saving_die"))
          return notify_fail("你正在救人, 沒有辦法運氣!!!\n");
        if( me->is_fighting() )
                return notify_fail("戰鬥中不能練內功\﹐會走火入魔。\n");
        ena_force = me->query_skill_mapped("force");
        if( !stringp(ena_force) )
                return notify_fail("你必須先用 enable 選擇你要用的內功\心法。\n");

        if( !arg ) kee_cost = 30;
        else if (!sscanf(arg, "%d", kee_cost))
                return notify_fail("你要花多少氣練功\﹖\n");

        if( kee_cost < 10 ) return notify_fail("你最少要花 10 點「氣」才能練功\。\n");

        if( (int)me->query("kee") < kee_cost )
                return notify_fail("你現在的氣太少了﹐無法產生內息運行全身經脈。\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
                return notify_fail("你現在精神狀況太差了﹐無法凝神專一﹗\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
                return notify_fail("你現在精力不夠﹐無法控制內息的流動﹗\n");
                
        if(me->query_temp("crazy"))
                return notify_fail("你正陷入狂暴狀態，無法靜下心來打坐。\n");

        write("你坐下來運氣用功\﹐一股內息開始在體內流動。\n");

        me->add("kee", -kee_cost);

        // This function ranged from 1 to 15 when kee_cost = 30
        // 運功跟根骨(con)有關
force_gain=kee_cost*(me->query("max_force")+me->query_con()*2)/2000;
if(me->query("class")=="fighter") force_gain=force_gain*1.2;
//原來的if(me->query("class")=="fighter") force_gain=force_gain*1.5;

// 98/6/4 ppl 反應以這種方法無法增加max_force
//經檢查結果 swordsman force lv 50 ,max_force ==250, kee 166
//如果一次exercise kee 160 ,force_gain~=160(250+40)/2000=23 難怪有人叫swordsman 去死
//這種情況想不出怎麼解決....其它force低的class大概也一樣
//不過我和chan認為不要讓ppl知道有改exercise...不然系統大亂,tintin開始出現
//so 我先加上這行,然後再進行討論解決的方法....:) ...Roger
/*取消......
if(me->query("class")=="swordsman" || me->query("class")=="poisoner"
|| me->query("class")=="taoist" || me->query("class")=="dancer")
force_gain=force_gain*1.2; //這是因為 lv 50 下 max_force only 250
                          //這樣一來若一次運完所有kee,force_gain~=46
                            //奇怪又被改了...太扯了....我修正回來:by chan
        // 請問這可能嗎?  ask by wade..

*/
        if( force_gain < 1 ) {
                write("但是當你行功\完畢﹐只覺得全身痠麻。\n");
                return 1;
        }

        // me->add("force", force_gain );
        // 增加亂數
        me->add("force",force_gain);

        if( (int)me->query("force") > (int)me->query("max_force") * 2) {
                if( (int)me->query("max_force") >= 
                ((int)me->query_skill("force",1)/5 +
         me->query_skill("force") ) *10
                  )
                {
                        write("當你的內息遍佈全身經脈時卻沒有功\力提昇的跡象﹐似乎內力修為已經遇到了瓶頸。\n");
                } else {
                        write("你的內力增強了﹗\n");
                        me->add("max_force", 1);
                }
                me->set("force", me->query("max_force"));
        }        
        if((random(me->query_skill("force",1))*4+me->query_skill("force",1))<
            random(me->query_skill(me->query_skill_mapped("force"),1))
           )
        {
          tell_object(me,
            "你的內力的功\力跟練功\根基不夠﹐強練內力﹐導致氣血失調。\n");
          me->apply_condition("ff_poison",(30-random(me->query_con()))/2);
        }
if(me->query("class")=="prayer"&&(ena_force=="superforce"))
if(me->query_skill("superforce",1) < 100) //渾天心法在lv 100之前沒有熟練值
     return 1;
con=me->query_con(); //加入体質的限制
con=con*6+20;
if(con < 100) //保證至少有一百
   con = 100;
if(me->query("class")=="fighter") //武者放寬一點二倍
  con=con*1.2;
if(me->query_skill(ena_force,1) > con)  
     return 1;
spi=me->query_spi();
sk_mount=me->query_skills();
sk_mount=sizeof(sk_mount);
if(spi > sk_mount)
me->improve_skill(ena_force,5);
else
me->improve_skill(ena_force,1);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise [<耗費「氣」的量﹐預設值 30>]
指令說明 :
           運氣練功﹐控制體內的氣在各經脈間流動﹐藉以
         訓練人體肌肉骨骼的耐力、爆發力﹐並且用內力的
         形式將能量儲備下來。
其他參考 :
           help stats
HELP
        );
        return 1;
}
