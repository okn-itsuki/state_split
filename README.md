# state_split

コンパイル時
```
make re
cc -Wall -Werror -Wextra main.c split_shell.a
```
## split_shell() info　
	is_setで定義されている文字をset文字としset文字で区切り、それぞれ二次元配列として保持する。
	そしてそれらを改行付きで順番に出力するプログラムである。
	また、このプログラムは状態（ステート）を持つ。コマンドライン引数で与えられた文字に特殊文字{',",\}が入っていた場合は特殊文字{',",\}で区切られた範囲を一つの文字列として扱う。

	使用時の注意
	1, 関数を外部で使用する場合、split_shell関数で確保した領域の開放は使用者の責任とする。
		この関数で確保した二次元配列はこのライブラリ内にある"all_free()"で開放しなくてはならない。
	2, この関数及びプログラムは、主にコマンドの解析を用途として設計してあります。
		そのためsize_tを超えるような文字数での動作は保証されていません。

	例）./split_shee "aa bb  cc	dd ee"
		0 : aa
		1 : bb
		2 : cc
		3 : dd
		4 : ee

## Error Handling

1) _EINVAL "Invalid argument"
	[aa bb "cc]など無効な引き数が渡された場合、エラー出力してNULLを返す。
2) _ENOMEM "Memory allocation failed."
malloc確保失敗時に途中まで確保されたメモリをfreeかつ、エラー出力してNULLを返す。