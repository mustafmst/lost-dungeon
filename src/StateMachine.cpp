#include "StateMachine.hpp"

void ld::StateMachine::HandleStateChanges()
{
	if(_isAdding)
	{
		if(_isReplacing && !_states.empty())
		{
			_states.pop();
		}
		_states.push(std::move(_newState));
		_states.top()->Init();
	} else if(_isRemoving && !_states.empty())
	{
		_states.pop();
	}
	
	_isAdding = false;
	_isReplacing = false;
	_isRemoving = false;
}

void ld::StateMachine::AddState(GameStateRef state, bool isReplacing)
{
	_newState = std::move(state);
	_isAdding = true;
	_isReplacing = isReplacing;
}

void ld::StateMachine::RemoveState()
{
	_isRemoving = true;
}

ld::GameStateRef &ld::StateMachine::CurrentState()
{
	_states.top();
}

