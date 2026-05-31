// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob;
        mapping skill;
        int cost, intt, literate,repeat,i;
        string name;

        repeat=0;
        if( me->is_fighting() )
                return notify_fail("你無法在戰鬥中專心下來研讀新知﹗\n");
        if(!arg)
                return notify_fail("你要讀什麼﹖\n");

        if(sscanf(arg,"%d %s",repeat,name)==2)
                arg=name;

        if(!repeat) repeat=1;

        if(!arg || !objectp(ob = present(arg, me)) )
                return notify_fail("你要讀什麼﹖\n");

        if( !mapp(skill = ob->query("skill")) )
          return notify_fail("這東西並不是武術秘籍, 你無法從它學到東西。\n");

        if( !(literate=me->query_skill("literate", 1)) )
                return notify_fail("你是個文盲﹐先學學讀書識字(literate)吧。\n");

        if ( (int)me->query("combat_exp") < skill["exp_required"] )
          return notify_fail ("你的實戰經驗不足﹐再怎麼讀也沒用。\n");

        if( !SKILL_D(skill["name"])->valid_learn(me) )
          return 0;
          //notify_fail("以你目前的能力﹐還沒有辦法學這個技能。\n");
// fix by Onion.
// skill 裡的 valid_learn() 都有寫 notify_fail(), 應以 skill 的敘述就好。
        if (ob->valid_learn(me)<0)
          return notify_fail ("據說你還不夠格讀此書哩!\n");

        cost = skill["difficulty"] - (intt=(int)me->query_int());
        if (cost < 0) cost = 0;
        cost = -literate/10+skill["sen_cost"] + skill["sen_cost"]  * cost/20;
        if( cost < 0 ) cost = skill["sen_cost"];
        if(me->query("class")=="scholar")
                cost=cost*2/3;
        for(i=0;i<repeat;i++)
        {
        if( (int)me->query("sen") < cost ) {
                write("你現在過於疲倦﹐無法專心下來研讀新知。\n");
                return 1;
        }

        if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
          return notify_fail ("你發現上面所說的對你而言都太淺了。\n");

        me->receive_damage("sen", cost);

        if( !me->query_skill(skill["name"], 1) )
                me->set_skill(skill["name"], 1);
        else {
          // Modify By chun 95/10/27
          // 由literate的影響改為受int的影響
          // wade fix in 1/4/1996, 改為混合 literate 與 悟性 兩者
          intt = intt/2;
          me->improve_skill(skill["name"], literate/10+random(intt)+5);
          if(me->query("class")=="scholar")
                me->improve_skill(skill["name"], literate/10+random(intt)+5);
        }

        message("vision", me->name() + "正專心地研讀" + ob->name()
                + "。\n", environment(me), me);

        write("你研讀有關" + to_chinese(skill["name"]) + "的技巧﹐似乎有點心得。\n");
        }
        return 1;
}

int help(object me)
{
   write( @HELP
指令格式 : study <物品名稱>
指令說明 :
           這個指令使你可以從秘笈或其他物品自學某些技巧,
           但前提是: 你不能是個『文盲』。
其他參考 :
           learn
HELP
   );
   return 1;
}
