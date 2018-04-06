#pragma once
#include <stack>
#include <utility>
#include "GameState.hpp"

namespace ld
{
	class StateMachine
	{
	private:
		std::stack<GameStateRef> _states;
		GameStateRef _newState;
		bool _isAdding, _isReplacing, _isRemoving;
	public:
		StateMachine() {}
		~StateMachine() {}
		void HandleStateChanges();
		void AddState(GameStateRef state, bool isReplacing = false);
		void RemoveState();
		GameStateRef &CurrentState();
	};
}

