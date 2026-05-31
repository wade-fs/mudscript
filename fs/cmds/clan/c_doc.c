// c_doc.c 製作幫派文件 by ACKY

void doc_edit( string str )
{
	write_file( "/doc/help/clan/"+this_player()->query("clan/name"), str, 1 );
	return;
}

int main( object me )
{
	if( !me->query("clan" ) || me->query("clan/rank") > 1 )
		return 0;
	me->edit( (: doc_edit :) );
	return 1;
}


int help( object me )
{
	write( "
	c_doc: 幫主編寫幫派文件。

	可在文件裡編寫幫規, 幫派歷史, 等資料。

	玩家 help <幫派中文名稱> 即可閱\讀幫派文件。

                                                         by ACKY 08/17/00
");
        return 1;
}
