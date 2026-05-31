//ex_equip.c by bss
//只要防具上有set("ex_def_power")，玩家穿上防具就可以增加query("ex_def_power")的防禦力
//修正新版，目前並不直接加上query("ex_def_power")的值，而是以等級的方式加防禦力
//一個等級目前的防禦力加LEVEL_UP所設定的點數，而query("ex_def_power")就是等級
//除等級可以加防禦力外，再增加「追加點數」，可以直接加query("ex_add_def")的防禦力
//初期會設定query("ex_add_def")只有四個狀態，也就是只會等於「1,2,3,4」
//防禦力會再加上query("ex_add_def")*4
//add at 09/25/03 by bss
#define LEVEL_UP 3

void wear(object eq,object me)
{
    int add_power,ex_add;

    add_power=eq->query("ex_def_power");
    ex_add=eq->query("ex_add_def");
    if(add_power <=0 || add_power > 12) add_power=0;
    if(ex_add <=0 || ex_add >4) ex_add=0;
    add_power*=LEVEL_UP;
    me->add_temp("apply/armor",add_power);
    me->set_temp("ex_def_power/"+eq->short(),add_power);
    ex_add*=4;
    me->add_temp("apply/armor",ex_add);
    me->add_temp("ex_def_power/"+eq->short(),ex_add);
    return ;
}
void unequip(object eq,object me)
{
    int add_power,ex_add;

    add_power=eq->query("ex_def_power");
    ex_add=eq->query("ex_add_def");
    if(add_power <= 0) return;
    if(ex_add <=0) return ;
    add_power*=LEVEL_UP;
    me->add_temp("apply/armor",-add_power);
    ex_add*=4;
    me->add_temp("apply/armor",-ex_add);
    if(me->query_temp("apply/armor") < 0 ) me->set_temp("apply/armor",0);
    me->delete_temp("ex_def_power/"+eq->short());
    return ;
}

