#pragma once

namespace Level
{
	enum class LevelNumber
	{
		ONE,
		TWO
	};

	enum class LinkedListType
	{
		SINGLE_LINKED_LIST,
		DOUBLE_LINKED_LIST
	};

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
	};

}