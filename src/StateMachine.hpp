#pragma once
#include <stack>
#include <utility>
#include "GameState.hpp"

namespace ld
{
	typedef std::shared_ptr<GameState> GameStateRef;
	class StateMachine
	{
	private:
		std::stack<GameStateRef> _states;
		GameStateRef _newState;
		bool _isAdding, _isReplacing, _isRemoving;
	public:
		StateMachine(): _states() {}
		~StateMachine() {}
		void HandleStateChanges();
		void AddState(GameStateRef state, bool isReplacing = false);
		void RemoveState();
		GameStateRef &CurrentState();
	};
}

