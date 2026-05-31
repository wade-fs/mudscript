// alias.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    int i,flag;
	mapping alias;
    object ob;
    string verb, replace, name, *vrbs;

    flag=0;
    if(wizardp(me)){
     if(arg){
      if(find_player(arg)){
        ob=find_player(arg);
        arg=0;
      }
       else if(FINGER_D->acquire_login_ob(arg)){
         ob = FINGER_D->acquire_login_ob(arg);
         arg=0;
       }
      else ob=me;
      alias=ob->query_all_alias();
      flag=1;
     }
    }
    if(!flag)
	alias = me->query_all_alias();
	if( !arg ) {
		if( !sizeof(alias) ) {
			write("你目前並沒有設定任何 alias。\n");
			return 1;
		} else  {
			write("你目前設定的所有命令替代如下﹕\n");
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				printf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]);
            printf("你現在一共設定有 %d 個alias!!\n",sizeof(vrbs));
			return 1;
		}
	}
  if(!sizeof(alias)) alias = allocate_mapping(0);
	if (strlen(arg) > 79) arg = arg[0..78];
	if( sscanf(arg, "%s %s", verb, replace)!=2 )
    if (stringp(alias[arg]))
		printf("你設定命令 %s 替換成 :\n%s\n", arg, alias[arg]);
	  else if (alias[arg])
		printf("你設定命令替換有問題，請刪除或重新設定。\n");
	  else
		printf("你沒有設定命令替換 "+arg+"\n");
	else if( verb=="alias" || verb == "go" || verb == "do" )
		return notify_fail("你不能將 "+verb+" 指令設定其他用途。\n");
	else if (verb == "-d") {
		printf("你刪除命令替換 %s:\n%s\n", replace, alias[replace]);
		me->set_alias(replace, 0);
	}
	else if( verb=="" )
		return notify_fail("你要設什麼 alias﹖\n");
	else {
		if (stringp(me->find_commands(verb))) return
		  notify_fail ("你會取代掉現有的命令, 請換個命令再來.\n");
		if (strsrch(replace, "$*") == -1) replace += " $*";
		printf("你設定命令替換 %s:\n%s\n", verb, replace);
		return me->set_alias(verb, replace);
	}

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : alias [-d] <欲設定之指令> <系統提供之指令>
指令說明 :
           有時系統所提供之指令需要輸入很長的字串, 在使用時
        (尤其是經常用到的) 或許會感覺不方便, 此時你(妳)可以
        用此一指令設定並替代原有之指令。 
範例:
	'alias sc score' 會以 sc 取代 score 指令。
	'alias' 後不加參數則列出你所有的替代指令。
	'alias sc' 會顯示 sc 這個替代指令。 (如果你有設的話)
	'alias -d sc' 會刪除你原先對 sc 的設定
 
其中可以用 $1, $2, $3 .... 來取代第一、第二、第三個參數﹐或是 $* 取代
所有的參數﹐如﹕
	'alias pb put $1 in $2'

則每當你(妳)打﹕
	pb bandage bag

就會取代成﹕
	put bandage in bag
	
HELP
);
        return 1;
}
