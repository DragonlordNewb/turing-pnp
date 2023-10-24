#pragma once

namespace turing {

	struct TransInstruct {

		bool moveLeft;
		bool moveRight;
		bool eraseSymbol;
		bool writeSymbol;
		int newSymbol;
		bool emitSymbol;
		int emission;
		int newState;

	};

	template <const const int tapeSize, const int emissionSize>
	class TuringMachine {

		private:

			int tape[tapeSize];
			int currentState;
			int currentLocation;

			virtual TransInstruct transition(int state, int symbol) = 0;
	
		public:

			int emission[emissionSize];
			int emissionCounter = 0;
		
			TuringMachine(int initialState, int initialTape[tapeSize]) {
	
				currentState = initialState;

				for (int i = 0; i < tapeSize; i++) {
					tape[i] = initialTape[i];
				}
				
			}

			void emit(int value) {
				emission[emissionCounter] = value;
				emissionCounter += 1;
			}

			void update() {
				TransInstruct transitionInstruction = transition(currentState, tape[currentLocation]);
				if (transitionInstruction.moveLeft) {
					currentLocation -= 1;
				}
				if (transitionInstruction.moveRight) {
					currentLocation += 1;
				}
				if (transitionInstruction.eraseSymbol) {
					tape[currentLocation] = 0;
				}
				if (transitionInstruction.writeSymbol) {
					tape[currentLocation] = transitionInstruction.newSymbol;
				}
				if (transitionInstruction.emitSymbol) {
					emit(transitionInstruction.emission);
				}
				currentState = transitionInstruction.newState;
			}
	
	};

}
