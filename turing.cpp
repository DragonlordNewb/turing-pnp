namespace turing {

	struct TransInstruct {

		bool moveLeft;
		bool moveRight;
		bool eraseSymbol;
		bool writeNewSymbol;
		int newSymbol;

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
	
	};

}
