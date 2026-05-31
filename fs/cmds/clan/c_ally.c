// by Avgirl 05/20/00
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int ally(object me,string clan);
int cally(object me,string clan);
int remove_accept(object me,object target);
int main(object me, string arg)
{
string clan;
if(this_player()->query("clan/rank")>3)
                return notify_fail("你無權使用這個指令!!\n");
        if(!arg)
                return help(this_player());
        if(sscanf(arg,"-cancel %s",clan))
                return cally(this_player(),clan);
        if(sscanf(arg,"%s",clan))
                return ally(this_player(),clan);

        return 1;

}
int ally(object me,string clan)
{
string ally_s;
        string *ally,*allyy;
        object target;
object obj;
        int i;

        if(me->is_fighting() || me->is_ghost())
                return notify_fail("很抱歉,你現在的情況不能使用這個指令。\n");
        if( !CLAN_D->have_clan( clan ) )
                return notify_fail("無此幫派。\n");
// 判斷有沒有同盟...

        ally=CLAN_D->clan_query(me->query("clan/id"),"ally");
        for(i=0;i<sizeof(ally);i++){
                if(ally[i]==clan)
                                return notify_fail("你已經跟他同盟了呀!!\n");
        }
        if( !target = find_player(CLAN_D->clan_query(clan, "master")))
                return notify_fail("對方的幫主不在,你無法對他提出要求。\n");

        if(me->query_temp("ally/invite"))
                return notify_fail("你已經邀請了,等對方回應中。\n");
        else {
if(!me->query_temp("ally/accept")) {
// 開始邀請....
        this_player()->set_temp("ally/invite",clan);
        target->set_temp("ally/accept",me->query("clan/id"));

        tell_object(target,GRN""+CLAN_D->clan_query(me->query("clan/id"),"name")+"想要跟你結為盟幫。\n"+
        "如果同意的話請打 cally "+ target->query_temp("ally/accept")+"。\n"NOR);

        call_out("remove_accept",30,target,this_player());
        return 1;
        }
}
if(me->query_temp("ally/accept")!=clan)
                return notify_fail("有人正在邀請你同盟,如不同意請稍等。
\n");
        else {
remove_call_out("remove_accept");
target->delete("ally");
me->delete("ally");
// 答應了....

// 開始設定..~~~~
        ally=CLAN_D->clan_query(me->query("clan/id"),"ally");
if(!ally) ally=({});
        if( pointerp(ally)) {
                ally += ({ clan });}
CLAN_D->clan_set(me->query("clan/id"),"ally",ally);

ally=({});
        ally=CLAN_D->clan_query(clan,"ally");
 if(!ally) ally=({});
ally_s=me->query("clan/id");
        if( pointerp(ally)) {
 ally += ({ ally_s });}
CLAN_D->clan_set(clan,"ally",ally);
// 結束設定~~~
shout(
                HIY""+me->query("clan/name")+" 決定和 "
        +CLAN_D->clan_query(clan,"name")+" 同盟了,希望能創造更強盛的幫派!!!\n"NOR);
        return 1;
        }
}
int remove_accept(object target,object me)
{
target->map_delete("ally");

me->map_delete("ally");

        tell_object(target,HIR""+me->query("clan/name")+"已經放棄同盟了。\n"NOR);
        write(HIR""+target->query("clan/name") + "沒有回應,您放棄同盟了。\n");
        return 1;
}

int cally(object me,string clan)
{
        string *ally,*allyy;
int tag;
        int i;

        if(me->is_fighting() || me->is_ghost())
                return notify_fail("很抱歉,你現在的情況不能使用這個指令。\n");
        if( !CLAN_D->have_clan( clan ) )
                return notify_fail("無此幫派。\n");
// 這邊開使是刪掉本身的ally....
        ally=CLAN_D->clan_query(me->query("clan/id"),"ally");
        for(i=0;i<sizeof(ally);i++){
if(ally[i]==clan) tag=1;
        }
if (!tag) return notify_fail("你們並沒有跟這一幫同盟!!\n");
        if( pointerp(ally)) {
                ally -= ({ clan });}
        CLAN_D->clan_set(me->query("clan/id"),"ally",ally);


// 刪掉對方的...
        ally=CLAN_D->clan_query(clan,"ally");
        if( pointerp(ally)) {
                  ally -= ({ me->query("clan/name") });}
CLAN_D->clan_set(clan,"ally",ally);

shout(
                HIY"從這一刻開始, "+me->query("clan/name")+" 決定取消和 "
        +CLAN_D->clan_query(clan,"name")+" 的同盟了!!!\n"NOR);

        return 1;
}


int help( object me )
{
        write("
        c_ally <幫派英文名稱>：跟某幫同盟。
        c_ally -cancel <幫派英文名稱>：跟某幫取消同盟。

                                        by avgirl 2000/05/20
");
        return 1;

}
