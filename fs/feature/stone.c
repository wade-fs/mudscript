//stone.c by bss
//如果殺死可以使自己得到經驗值的mob，只要自己的exp>MIN_EXP，就有機會得到寶石
//掉下來的機率部分好像設計的蠻麻煩的
//design on 09/26/03
#include <ansi.h>
#define MIN_EXP         6000000
#define BLESS_RATIO     3
#define SOUL_RATIO      7
#define LIFE_RATIO      1
#define LUCKY_RATIO     1
#define MAX_ADD_RATIO   100
#define RATIO_BASE      2000
#define BLESS_FILE      "/obj/stone/bless"
#define SOUL_FILE       "/obj/stone/soul"
#define LIFE_FILE       "/obj/stone/life"
#define LUCKY_FILE      "/obj/stone/lucky"
#define STONE_RATIO     ({BLESS_RATIO,SOUL_RATIO,LIFE_RATIO,LUCKY_RATIO});
#define STONE_FILE      ({BLESS_FILE,SOUL_FILE,LIFE_FILE,LUCKY_FILE}); 

void main(object ppl,object mob)
{
    int add_ratio;//如果mob身上有設定stone_kind的話，可以增加掉寶的機率，增加query("add_stone_ratio")的機率
    int i;
    object stone,where;
    int *stone_ratio;
    string *stone_file;
    
    if(ppl->query("combat_exp") < MIN_EXP) return ;
    add_ratio=mob->query("add_stone_ratio");
    if(add_ratio > MAX_ADD_RATIO) add_ratio=MAX_ADD_RATIO;
    if(wizardp(ppl) && ppl->query("env/must_get_stone")) add_ratio=RATIO_BASE;//for wiz test
    stone_ratio=STONE_RATIO;
    stone_file=STONE_FILE;
       
    //每次一有機會掉寶石，就先選擇只有四種裡面的其中一種寶石會掉，接下來就看運氣囉
    i=random(4);
    if(stone_ratio[i] + add_ratio > random(RATIO_BASE)){
      stone=new(stone_file[i]);
      where=environment(ppl);
      message_vision(HIW"「叮」的一聲，一顆"+stone->name()+"從$N的身上掉了出來！！！\n"NOR,mob);
      stone->move(where);
    }  
    return ;
}
